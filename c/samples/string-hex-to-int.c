#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned char char2int(const unsigned char *pChar)
{
	unsigned char ret = -1;

    // 0x30 = '0', 0x39 = '9'
	if ((*pChar >= 0x30) && (*pChar <= 0x39)) {
		ret = *pChar - 0x30;
	}
    // 0x41 = 'A', 0x46 = 'F'
    else if ((*pChar >= 0x41) && (*pChar <= 0x46)) {
		ret = *pChar - 0x37;
	}
    // 0x61 = 'a', 0x66 = 'f'
    else if ((*pChar >= 0x61) && (*pChar <= 0x66)) {
        ret = *pChar - 0x57;
    }
    else {
        printf("Invalid char, cannot convert to int!\n");
        exit(1);
    }

    return ret;
}

static int nchar2int(const char *pChar, int num)
{
	int	ret = 0;
	int cnt = 0;
    unsigned char cval = 0;

	for (cnt = 0; cnt <num; cnt++) {
        cval = char2int((unsigned char *)(pChar+cnt));
		ret += cval << ((num-cnt-1)*4);
	}

	return ret;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s char-string\n", argv[0]);
        return -1;
    }

    int nlen = 0;
    nlen = strlen(argv[1]);

    printf("%s = %d (dec)\n", argv[1], nchar2int(argv[1], nlen));

    return 0;
}