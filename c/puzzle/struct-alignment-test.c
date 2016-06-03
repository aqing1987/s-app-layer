#include <stdio.h>

// not alignment for 4B

int main()
{
#pragma pack (1) // 1byte alignment
    int i = 0;
    unsigned char buf[8];

    for (i = 0; i < 8; i++) {
        buf[i] = i;
        printf("buf[%d] = 0x%x\n", i, buf[i]);
    }

    for (i = 0; i < 5; i++)
        printf("*(int *)&buf[%d] = 0x%x\n", i, *(int *)&buf[i]);
#pragma pack ()

    struct A {
        int a;
        char b;
        short c;
    };

    struct B {
        char b;
        int a;
        short c;
    };

#pragma pack (2) // 2bytes alignment
    struct C {
        char b;
        int a;
        short c;
    };
#pragma pack () // restore to default alignment

#pragma pack (1) // 1byte alignment
    struct D {
        char b;
        int a;
        short c;
    };
#pragma pack ()// restore to default alignment

    int s1 = sizeof(struct A);
    int s2 = sizeof(struct B);
    int s3 = sizeof(struct C);
    int s4 = sizeof(struct D);
    printf("s1 = %d, s2 = %d, s3 = %d, s4 = %d\n",
           s1, s2, s3, s4);

    typedef struct {
        unsigned char s1;
        unsigned char s2;
        unsigned char s3;
        unsigned char arr1[4];
    } NewT;

    NewT test;
    test.s1 = 0x10;
    test.s2 = 0x20;
    test.s3 = 0x40;
    test.arr1[0] = 0xAA;
    test.arr1[1] = 0xBB;
    test.arr1[2] = 0xCC;
    test.arr1[3] = 0xDD;

    printf("*(int *)&test.arr1[0] = 0x%x\n", *(int *)&test.arr1[0]);

    return 0;
}
