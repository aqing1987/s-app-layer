/**
 * stdin, stdout is line buffered, buffer size = 1024
 * stderr is nonbuffered, buffer size = 1
 * regular files are fully buffered, buffer size = 4096
 * 4096 is st_blksize value from the stat structure.
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void pr_stdio(const char *name, FILE *fp)
{
    printf("stream = %s, ", name);

    // the following is nonportable
    if (fp->_IO_file_flags & _IO_UNBUFFERED) {
        printf("unbuffered");
    } else if (fp->_IO_file_flags & _IO_LINE_BUF) {
        printf("line buffered");
    } else {
        printf("fully buffered");
    }

    printf(", buffer size = %d\n", (int)(fp->_IO_buf_end - fp->_IO_buf_base));
}

int main(int argc, char *argv[])
{
    FILE *fp;

    // stdin, stdout, stderr connected to terminal
    fputs("enter any character\n", stdout);
    if (getchar() == EOF) {
        perror("getchar err");
    }
    fputs("one line to standard error\n", stderr);

    pr_stdio("stdin", stdin);
    pr_stdio("stdout", stdout);
    pr_stdio("stderr", stderr);

    if ((fp = fopen("/etc/magic", "r")) == NULL) {
        perror("fopen err");
    }
    if (getc(fp) == EOF) {
        perror("getc");
    }
    pr_stdio("/etc/magic", fp);
    fclose(fp);

    //int stat(const char *path, struct stat *buf);
    struct stat sbuf;
    if (stat("/etc/magic", &sbuf) < 0) {
        perror("stat");
    }
    printf("blksize = %d\n", (int)sbuf.st_blksize);

    return 0;
}
