// cubes.cpp -- regular and reference arguments
// the refcube() function modifies the value of x in main()
// and cube() doesn't.
#include <iostream>

double cube(double a);
double refcube(double &ra);

int main(int argc, char *argv[])
{
    using namespace std;

    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = cube of " << x << endl;
    return 0;
}

double cube(double a)
{
    a *= a * a;
    return a;
}

/*
 * If your intent is that a function use the information passed to
 * it without modifying the information, and if you're using a
 * reference, you should use a constant reference. If you do this, the
 * compiler generates an error message when it finds code altering
 * the value of ra.
 */
double refcube(double &ra)
{
    ra *= ra * ra;
    return ra;
}
