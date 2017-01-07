// address.cpp -- using the & operator to find addresses

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int donuts = 6;
    double cups = 4.5;

    cout << "donuts value = " << donuts;
    cout << " and donuts address = " << &donuts << endl;
    // NOTE: you may need to use unsigned (&donuts)
    // and unsigned (&cpus)
    cout << "cups value = " << cups;
    cout << " and cpus address = " << &cups << endl;

    return 0;
}
