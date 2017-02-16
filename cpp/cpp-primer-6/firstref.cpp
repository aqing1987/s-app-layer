// firstref.cpp -- defining and using a reference
// the main use for a reference variable is as a formal
// argument to a function. If you use a reference as an
// argument, the function works with the original data
// instead of with a copy. References provide a conveniet
// alternative to pointers for processing large structures
// with a function, and they are essential for designing classes.
#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int rats = 101;
    // int & (that is, it is a reference to an int variable)
    // Note: you should initialize a reference variable when you
    // declare it.
    int & rodents = rats; // rodents is a reference
    // int * prats = &rats; // prats a pointer

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    rodents++;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    // some implementations require type casting the following
    // addresses to type unsigned
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    return 0;
}
