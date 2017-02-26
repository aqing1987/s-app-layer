// template_choices.cpp -- chosing a template
#include <iostream>

/*
 * eliminates the template prototype and places the
 * template function definition at the top of the file.
 * As with regular functions, a template function definition
 * can act as its own prototype if it appears before the function
 * is used.
 */
template <class T> // or template <typename T>
T lesser(T a, T b) // #1
{
    return a < b ? a : b;
}

int lesser(int a, int b) // #2
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;

    return a < b ? a : b;
}

int main(int argc, char *argv[])
{
    using namespace std;

    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    // the function call arguments match both the template function
    // and the non template function, so the non template function is chosen
    cout << lesser(m, n) << endl; // use #2
    cout << lesser(x, y) << endl; // use #1 with double

    /*
     * The presence of the angle brackets in lesser<>(m, n) indicates that
     * the compiler should choose a template function rather than a non
     * template function.
     */
    cout << lesser<>(m, n) << endl; // use #1 with int

    /*
     * have a request for an explicit instantiation using int for T,
     * and that's the function that gets used.
     */
    cout << lesser<int>(x, y) << endl; // use #1 with int
    return 0;
}


