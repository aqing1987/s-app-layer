// formore.cpp -- more looping with for
#include <iostream>

// it's usually a good idea to define a const value
// to represent the number of elements in an array.
const int ArSize = 16; // example of external declaration

int main(int argc, char *argv[])
{
    using namespace std;

    long long factorials[ArSize];

    factorials[1] = factorials[0] = 1LL;
    for (int i = 2; i < ArSize; i++) {
        factorials[i] = i * factorials[i-1];
    }

    for (int i = 0; i < ArSize; i++) {
        cout << i << "! = " << factorials[i] << endl;
    }

    return 0;
}
