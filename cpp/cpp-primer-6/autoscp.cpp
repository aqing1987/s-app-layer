// autoscp.cpp -- illustrating scope of automatic variables
#include <iostream>

void oil(int x);

int main(int argc, char *argv[])
{
    using namespace std;

    int texax = 31;
    int year = 2011;

    cout << "In main(), texax = " << texax << ", &texas = ";
    cout << &texax << endl;
    cout << "In main(), year = " << year << ", &year = ";
    cout << &year << endl;

    oil(texax);

    cout << "In main(), texax = " << texax << ", &texas = ";
    cout << &texax << endl;
    cout << "In main(), year = " << year << ", &year = ";
    cout << &year << endl;

    return 0;
}

/*
 * for texas, we say the new definition hides the prior definition.
 * The new definition is in scope, and the old definition is temporarily
 * out of scope. When the program leaves the block, the original definition
 * comes back into scope.
 */
void oil(int x)
{
    using namespace std;
    int texas = 5;

    cout << "In oil(), texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "In oil(), x = " << x << ", &x = ";
    cout << &x << endl;

    { // start a block
        int texas = 113;
        cout << "In block, texas = " << texas;
        cout << ", &texas = " << &texas << endl;
        cout << "In block, x = " << x << ", &x = ";
        cout << &x << endl;
    } // end a block

    cout << "Post-block texas = " << texas;
    cout << ", &texas = " << &texas << endl;
}