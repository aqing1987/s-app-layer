// ruler.cpp -- using recursion to subdivide a ruler
// recursion is particularly useful for situations that call
// for repeatedly subdividing a task into two smaller, similar
// tasks.
#include <iostream>

const int Len = 66;
const int Divs = 6;

void subdivide(char ar[], int low, int high, int level);

int main(int argc, char *argv[])
{
    char ruler[Len];
    int i;
    for (i = 1; i < Len - 2; i++) {
        ruler[i] = ' ';
    }
    ruler[Len-1] = '\0';

    int max = Len - 2;
    int min = 0;
    ruler[min] = ruler[max] = '|';
    std::cout << ruler << std::endl;
    for (i = 1; i <= Divs; i++) {
        subdivide(ruler, min, max, i);
        std::cout << ruler << std::endl;
        for (int j = 1; j < Len - 2; j++) {
            ruler[j] = ' '; // reset to blank ruler
        }
    }
    return 0;
}

// level to control the recursion level
// the function with a level of 0 terminates.
void subdivide(char ar[], int low, int high, int level)
{
    if (level == 0) {
        return;
    }

    int mid = (high + low) / 2;
    ar[mid] = '|';
    subdivide(ar, low, mid, level - 1);
    subdivide(ar, mid, high, level - 1);
}