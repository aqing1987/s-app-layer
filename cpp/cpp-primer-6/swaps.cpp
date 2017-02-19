// swaps.cpp -- swapping with references and with pointers
// the reference and pointer methods both successfully swap
// the contents of the two wallets, whereas the passing by
// value method fails.
#include <iostream>

void swapr(int & a, int & b); // a, b are aliases for ints
void swapp(int * p, int * q); // p, q are addresses of ints
void swapv(int a, int b); // a, b are new variables

int main(int argc, char *argv[])
{
    using namespace std;

    int wallet1 = 300;
    int wallet2 = 350;

    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2); // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointers to swap contents again:\n";
    swapp(&wallet1, &wallet2); // pass addresses of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Trying to use passing by value:\n";
    swapv(wallet1, wallet2); // pass values of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    return 0;
}

// use references
// reference function arguments are initialized to the argument
// passed by the function call.
void swapr(int & a, int & b)
{
    int temp;

    temp = a; // use a, b for values of variables
    a = b;
    b = temp;
}

// use pointers
void swapp(int * p, int * q)
{
    int temp;

    temp = *p; // use *p, *q for values of variables
    *p = *q;
    *q = temp;
}

// try using values
void swapv(int a, int b)
{
    int temp;

    temp = a; // use a, b for values of variables
    a = b;
    b = temp;
}
