// inline.cpp -- using an inline function
// If you have been using C macros to perform function-like
// services, you should consider converting them to C++
// inline functions.
#include <iostream>

// Note that the entire definition is on one line. That's not
// required, but if the definition doesn't fit on one or two
// lines, the function is probably a poor candidate for an
// inline function
// an inline function definition
inline double square(double x) { return x* x; }

int main(int argc, char *argv[])
{
    using namespace std;

    double a, b;
    double c = 13.0;

    a = square(5.0);
    b = square(4.5 + 7.5); // can pass expressions
    cout << "a = " << a << ", b = " << b << "\n";
    cout << "c = " << c;
    cout << ", c squared = " << square(c++) << "\n";
    cout << "Now c = " << c << "\n";

    return 0;
}
