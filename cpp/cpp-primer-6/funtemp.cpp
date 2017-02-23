// funtemp.cpp -- using a function template
// The benefits of templates are that they make generating multiple function
// definitions simpler and more reliable.
// More typically, templates are placed in a header file that is then included
// in the file using them.
#include <iostream>

// function template prototype
template <typename T> // or class T
void Swap(T &a, T &b);

int main(int argc, char *argv[])
{
    using namespace std;

    int i = 10;
    int j = 20;

    cout << "i, j = " << i << "," << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j); // generates void Swap(int &, int &)
    cout << "Now i, j = " << i << "," << j << ".\n";

    double x = 24.5;
    double y = 81.7;
    cout << "x, y = " << x << ", " << y << ".\n";
    cout << "Using compiler-generated double swapper:\n";
    Swap(x, y); // generates void Swap(double &, double &)
    cout << "Now x, y = " << x << ", " << y << ".\n";

    return 0;
}

// function template definition
template <typename T> // or class T
void Swap(T & a, T & b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
