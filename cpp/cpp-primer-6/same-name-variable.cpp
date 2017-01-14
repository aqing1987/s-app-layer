// what happens if you declare a variable in a block that has the same
// name as one outsie the block?
// the new variable hides the old one from its point of appearance until
// the end of the block. Then the old one becomes visible again.
#include <iostream>

int main(int argc, char *argv[])
{
    using std::cout;
    using std::endl;

    int x = 20; // original x
    { // block starts
        cout << x << endl; // use original x
        int x = 100; // new x
        cout << x << endl; // use new x
    } // block ends

    cout << x << endl; // use original x

    return 0;
}
