/**
 * copy a string
 * char *strncpy(char *dest, const char *src, size_t n);
 *
 * The strncpy() function is similar, except that at most n bytes
 * of src are copied. Warning: If there is no null byte among the
 * first n bytes of src, the string placed in dest will not be
 * null-terminated.
 * */
#include <stdio.h>
#include <string.h>

char *my_strncpy(char *dst, const char *src, size_t n)
{
    size_t i = 0;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dst[i] = src[i];
    for (; i < n; i++)
        dst[i] = '\0';

    return dst;
}

int main()
{
    char dst_str[16];
    char dst2[16];
    const char *src = "it's an amazing show!";

    memset(dst_str, 0, sizeof(dst_str));
    memset(dst2, 0, sizeof(dst2));
    
    strncpy(dst_str, src, sizeof(dst_str)-1);
    my_strncpy(dst2, src, sizeof(dst2)-1);
    printf("dst1 = %s, dst2 = %s\n", dst_str, dst2);
    
    return 0;
}
