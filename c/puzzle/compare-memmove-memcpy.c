/**
 * memmove, copy memory area
 * void *memmove(void *dest, const void *src, size_t n);
 *
 * the memmove() function copies n bytes from memory area src to memory
 * area dest. The memory areas may overlap.
 *
 * void *memcpy(void *dest, const void *src, size_t n);
 * the memcpy() function copies n bytes from memory area src to memory
 * area dest. The memory areas must not overlap.
 * */
#include <stdio.h>
#include <string.h>

#define BUF_LEN 20

//        |<-         length            ->|
//|---+---+---+---+---+---+---+---+---+---|
//| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
//|---+---+---+---+---+---+---+---+---+---|
//        |               |
//      psrc             pdst
int main()
{
    char msrc[BUF_LEN];
    char *mdst = &msrc[6]; // overlap with msrc

    memset(msrc, 0, BUF_LEN);
    strcpy(msrc, "0123456789abcdef");

    printf("msrc = %s\n", msrc);

    // void *memmove(void *dest, const void *src, size_t n);
    memmove(mdst, msrc, 16);

    // check result
    // 0123450123456789abcdef (ok)
    printf("msrc(memmove) = %s\n", msrc);

    memset(msrc, 0, BUF_LEN);
    strcpy(msrc, "0123456789abcdef");
    printf("msrc = %s\n", msrc);

    // check memcpy result
    // 01234501234567234567ef (error)
    memcpy(mdst, msrc, 16);
    printf("msrc(memcpy) = %s\n", msrc);

    return 0;
}
