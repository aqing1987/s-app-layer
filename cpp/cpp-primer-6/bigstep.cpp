// bigstep.cpp -- count as directed
#include <iostream>

int main(int argc, char *argv[])
{
    using std::cout; // a using declaration
    using std::cin;
    using std::endl;

    cout << "Enter an integer: ";
    int by;
    cin >> by;
    cout << "Counting by " << by << "s:\n";
    // 1. update expression can by any valid expression
    // 2. it often is a better idea to test for inequality than equality
    for (int i = 0; i < 100; i = i + by) {
        cout << i << endl;
    }

    return 0;
}
