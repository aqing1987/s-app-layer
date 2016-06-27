#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/mman.h>
#include <fcntl.h>

const char *g_tf_dir = "/storage/XXDIR/";
const char *g_usb_dir = "/external/XXDIR/";

#define error(fmt,args...)                      \
    printf(fmt, ##args) ;                       \
    printf(":%s\n",strerror(errno))

int cp_map(int srcfd, int dstfd, size_t len)
{
    char *src = NULL;
    char *dst = NULL;

    if ((src = mmap(0, len, PROT_READ, MAP_SHARED, srcfd, 0)) == MAP_FAILED) {
        error("mmap src error");
        return -1;
    }
    if ((dst = mmap(0, len, PROT_WRITE, MAP_SHARED, dstfd, 0)) == MAP_FAILED) {
        error("mmap dst error");
        return -1;
    }
    if (memcpy(dst, src, len) == NULL) {
        error("memcpy error");
        return -1;
    }

    munmap(src, len);
    munmap(dst, len);

    return 0;
}

int cp_rw(int srcfd, int dstfd, char *buf, int len)
{
    int nread = 0;

    while ((nread = read(srcfd, buf, len)) > 0) {
        if (write(dstfd, buf, nread) != nread) {
            error("write error");
            return -1;
        }
    }

    if (nread == -1) {
        error("read error");
        return -1;
    }

    return 0;
}

int list_and_move(int flag)
{
    if (flag != 1 && flag != 2) {
        printf("invalid args.\n");
        return -1;
    }

    char cpbuf[8192];
    static int total = 0;
    struct dirent * p_dirent = NULL;
    DIR *p_dir = NULL;
    char cmd[256];
    char src_file[256];
    char dst_file[256];
    int srcfd, dstfd;
    struct stat filestat;

    memset(cpbuf, 0, sizeof(cpbuf));
    memset(src_file, 0, sizeof(src_file));
    memset(dst_file, 0, sizeof(dst_file));
    memset(cmd, 0, sizeof(cmd));

    if (flag == 1) {
        p_dir = opendir(g_tf_dir);
    }
    else {
        p_dir = opendir(g_usb_dir);
    }

    if (!p_dir) {
        perror("opendir");
        return -1;
    }

    errno = 0;
    while (1) {
        memset(cmd, 0, sizeof(cmd));
        memset(cpbuf, 0, sizeof(cpbuf));

        p_dirent = readdir(p_dir);
        // error
        if (p_dirent == NULL && errno != 0) {
            perror("readdir");
            closedir(p_dir);
            return -2;
        }

        // search end.
        if (p_dirent == NULL && errno == 0) {
            break;
        }

        // overlook . && ..
        if (strcmp(p_dirent->d_name, ".") == 0 || strcmp(p_dirent->d_name, "..") == 0)  {
            continue;
        }

        // === valid files process
        if (strstr(p_dirent->d_name, ".mp4")) {
            if (flag == 1) {
                sprintf(src_file, "%s%s", g_tf_dir, p_dirent->d_name);
                sprintf(dst_file, "%s%s", g_usb_dir, p_dirent->d_name);
            }
            else {
                sprintf(src_file, "%s%s", g_usb_dir, p_dirent->d_name);
                sprintf(dst_file, "%s%s", g_tf_dir, p_dirent->d_name);
            }

            printf("\t\t === %d === \n", total++);
            //printf("%s\n", cmd);
            //system(cmd);
            //sleep(10);

            printf("src file = %s\n", src_file);
            printf("dst file = %s\n", dst_file);
            if ((srcfd = open(src_file, O_RDONLY)) == -1) {
                error("open %s error", src_file);
                goto out;
            }
            if ((dstfd = open(dst_file, O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1) {
                error("creat %s error", dst_file);
                goto out;
            }

#if 1
            fstat(srcfd, &filestat);
            if (lseek(dstfd, filestat.st_size, SEEK_SET) == -1) {
                error("lseek error");
                goto out;
            }
            cp_map(srcfd, dstfd, filestat.st_size);
#else
            cp_rw(srcfd, dstfd, cpbuf, sizeof(cpbuf));
#endif
            close(srcfd);
            close(dstfd);

            sprintf(cmd, "rm %s", src_file);
            system(cmd);
            printf("cmd = %s\n", cmd);
            sleep(5);
        }
    }

out:
    if (srcfd) {
        close(srcfd);
    }

    if (dstfd) {
        close(dstfd);
    }

    closedir(p_dir);

    return 0;
}

void * compute_sys_load(void *arg)
{
    while (1) {
        printf("++++++++++++++++++++++++++++++\n");
        system("uptime");
        printf("------------------------------\n");
        system("free | head -2");
        printf("++++++++++++++++++++++++++++++\n");
        sleep(3);
    }

    return 0;
}

int main(int argc, char **argv)
{
    int ret = 0;
    pthread_attr_t attr128;
    pthread_t sys_load_thread;

    if (argc != 2) {
        printf("Usage: %s op\n", argv[0]);
        printf("op = 1 for mv %s* %s\n", g_tf_dir, g_usb_dir);
        printf("op = 2 for mv %s* %s\n", g_usb_dir, g_tf_dir);
        return -1;
    }

    pthread_attr_init(&attr128);
    pthread_attr_setstacksize(&attr128, 128 * 1024);
    pthread_attr_setdetachstate(&attr128, PTHREAD_CREATE_DETACHED);
    pthread_create(&sys_load_thread, &attr128, compute_sys_load, NULL);
    pthread_attr_destroy(&attr128);

    list_and_move(atoi(argv[1]));

    return 0;
}
