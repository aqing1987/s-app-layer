#include <stdio.h>
#include "inc.h"

int g_total;

void f()
{
    g_total = 3;
    printf("use module g_total = %d\n", g_total);
}
