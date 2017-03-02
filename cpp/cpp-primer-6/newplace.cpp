// newplace.cpp -- using placement new
#include <iostream>
#include <new> // for placement new

const int BUF = 512;
const int N = 5;
char buffer[BUF]; // chunk of memory

int main(int argc, char *argv[])
{
    using namespace std;

    double *pd1, *pd2;
    int i;

    cout << "Calling new and placement new:\n";
    pd1 = new double[N]; // use heap
    pd2 = new (buffer) double[N]; // use buffer array

    for (i = 0; i < N; i++) {
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    }
    // buffer is pointer-to-char, that's why the program uses
    // a (void *) cast for buffer; otherwise, cout would try
    // to display a string.
    cout << "Memory addresses:\n" << " heap: " << pd1
         << " static: " << (void *) buffer << endl;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++) {
        cout << pd1[i] << " at " << &pd1[i] << ";";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    cout << "\nCalling new and placement new a second time:\n";
    double *pd3, *pd4;
    pd3 = new double[N]; // find new address
    // the important fact here is that placement new simply uses
    // the address that is passed to it; it doesn't keep track of
    // whether that location has already been used, and it doesn't
    // search the block for unused memory.
    pd4 = new (buffer) double[N]; // overwrite old data
    for (i = 0; i < N; i++) {
        pd4[i] = pd3[i] = 1000 + 40.0 * i;
    }
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++) {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }

    cout << "\nCalling new and placement new a third time:\n";
    // frees up the block of memory, and as a result, the next call
    // to new is able to reuse that block.
    delete [] pd1;

    pd1 = new double[N];
    pd2 = new (buffer + N * sizeof(double)) double[N];
    for (i = 0; i < N; i++) {
        pd2[i] = pd1[i] = 1000 + 60.0 * i;
    }
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++) {
        cout << pd1[i] << " at " << &pd1[i] << ";";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    delete [] pd1;
    delete [] pd3;

    return 0;
}
