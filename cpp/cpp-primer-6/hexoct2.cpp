// hexoct2.cpp -- display values in hex and octal

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "Monsieur cuts a striking figure!" << endl;
    cout << "chest = " << chest << " (decimal for 42)" << endl;
    cout << hex; // manipulator for chaning number base
    cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
    cout << oct; // manipulator for chaning number base
    cout << "inseam = " << inseam << " (octal for 42)" << endl;

    return 0;
}
