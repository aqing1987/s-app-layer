#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#ifdef DEBUG
#define __D(fmt, args...) fprintf(stderr, "Debug: " fmt, ## args)
#else
#define __D(fmt, args...)
#endif

#define PROC_MEM_SIZE 4096*3
#define MAX_SHARE_PROC	9

static int g_mid;

/**
 * @brief Initialize shared memory driver.
 * @note Once initialed, the memory ID is saved to global variable.
 * @return Memory ID
 * @retval -1 Fail to initialize shared memory.
 */
int share_mem_init(int key)
{
    // int shmget(key_t key, size_t size, int shmflg);
	g_mid = shmget(key, PROC_MEM_SIZE * MAX_SHARE_PROC, IPC_CREAT | 0660);
	if (g_mid < 0) {
        g_mid = shmget(key, 0, 0);
    }

	__D("shared memory id:%d\n", g_mid);
	if (g_mid < 0) {
        return -1;
    }

	return g_mid;
}

/**
 * @brief Read shared memory driver.
 * @param offset [i]  memory offset
 * @param *buf [i]  pointer to memory buffer
 * @param length [i]  data length to read
 */
void share_mem_read(int offset, void *buf, int length)
{
    // void *shmat(int shmid, const void *shmaddr, int shmflg);
    // shmat() attaches the System V shared memory segment identified by shmid
    // to the address space of the calling process.
    // If  shmaddr  is NULL, the system chooses a suitable (unused) address at
    // which to attach the segment.
	char *pSrc = shmat(g_mid, NULL, 0);
	__D("%s\n", __func__);
	__D("offset: %d\n", offset);
	__D("buf: %x\n", (unsigned int) buf);
	__D("length: %d\n", length);
	memcpy(buf, pSrc + offset, length);

    // int shmdt(const void *shmaddr);
    // shmdt() detaches the shared memory segment located at the address spec‐
    // ified  by  shmaddr  from the address space of the calling process.
    // The to-be-detached segment must be currently attached with shmaddr equal to
    // the value returned by the attaching shmat() call.
	shmdt(pSrc);
}

/**
 * @brief Write shared memory driver.
 * @param offset [i]  memory offset
 * @param *buf [i]  pointer to memory buffer
 * @param length [i]  data length to read
 */
void share_mem_write(int offset, void *buf, int length)
{
	char *pDst = shmat(g_mid, NULL, 0);

	__D("%s\n", __func__);
	__D("offset: %d\n", offset);
	__D("buf: %x\n", (unsigned int) buf);
	__D("length: %d\n", length);
	__D("pDst: %p\n", pDst);
	__D("pDst + offset: %p\n", pDst + offset);
	memcpy(pDst + offset, buf, length);

    shmdt(pDst);
}

#define BUF_MAX 128

int main(int argc, char *argv[])
{
    char write_buf[BUF_MAX];
    char read_buf[BUF_MAX];

    memset(write_buf, 0, sizeof(write_buf));
    memset(read_buf, 0, sizeof(read_buf));

    if (share_mem_init(0x36f9) < 0) {
        printf("err init.\n");
        return -1;
    }

    int i = 0;
    for (i = 0; i < BUF_MAX; i++) {
        write_buf[i] = i;
    }

    share_mem_write(100, write_buf, BUF_MAX);
    share_mem_read(100, read_buf, BUF_MAX);

    for (i = 0; i < BUF_MAX; i++) {
        printf("%4x ", read_buf[i]);
        if (i % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}
