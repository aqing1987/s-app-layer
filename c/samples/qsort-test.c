#include <stdio.h>
#include <stdlib.h>

#define NUM 5

void print_min(int a, int b)
{
    if (a < b)
        printf("%d\n", a);
    else
        printf("%d\n", b);
}

int compare(const void *ele1, const void *ele2)
{
    unsigned int *p1 = NULL, *p2 = NULL;

    p1 = (unsigned int *)ele1;
    p2 = (unsigned int *)ele2;

    return (*p1 - *p2);
}

int main()
{
      // test function pointer
    void (*pf)(int, int);
    int x = 4, y = 5;

    pf = print_min;
    pf(x, y);

    /*
      void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *));

      The comparison function must return an integer less than, equal to, or
      greater than zero if the first argument is considered to be respec‐
      tively less than, equal to, or greater than the second.  If two members
      compare as equal, their order in the sorted array is undefined.
    */

      // test qsort api
    int i = 0;
    unsigned int arr[NUM] = {5, 9, 1, 10, 3};
    qsort(arr, NUM, sizeof(unsigned int), compare);
    for (i = 0; i < NUM; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
