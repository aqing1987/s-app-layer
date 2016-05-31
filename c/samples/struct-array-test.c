#include <stdio.h>

#define PIN_NUM 4

struct pindesc {
    unsigned char pin;
    unsigned char pin_val;
};

struct pindesc pindescs[PIN_NUM] = {
    {1, 0x01},
    {2, 0x02},
    {3, 0x04},
    {4, 0x08},
};

int main(int argc, char *argv[])
{
    int i = 0;
    
    for (i = 0; i < PIN_NUM; i++) {
        printf("pin = %d, pin_val = 0x%x\n",
               pindescs[i].pin, pindescs[i].pin_val);
    }
    
    return 0;
}
