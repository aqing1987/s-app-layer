// support.cpp -- use external variable
// compile with external.cpp

#include <iostream>

extern double warming; // use warming from another file

// function prototypes
void update(double dt);
void local();

using std::cout;

void update(double dt) // modifies global variable
{
    extern double warming; // optional redeclaration

    warming += dt; // uses global warming
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";
}

/*
 * when you define a local variable that has the same  name
 * as a global variable, the local version hides the global version.
 * C++ goes a step beyond C by offering the scope-resolution operator
 * (::). When it is prefixed to the name of a variable, this operator
 * means to use the global version of that variable.
 */
void local() // uses local variable
{
    double warming = 0.8; // new variable hides external one

    cout << "Local warming = " << warming << " degrees.\n";
    // access global variable with the scope resulution operator
    cout << "But global warming = " << ::warming;
    cout << " degrees.\n";
}