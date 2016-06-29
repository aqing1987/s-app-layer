#include <stdio.h>
#include "inc.h"

int g_total;

int main()
{
    g_total = 5;

    f();
    printf("use main g_total = %d\n", g_total);

    return 0;
}
