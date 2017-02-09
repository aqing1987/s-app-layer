// strgback.cpp -- a function that returns a pointer to char
#include <iostream>

char * buildstr(char c, int n); // prototype

int main(int argc, char *argv[])
{
    using namespace std;
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter an integer: ";
    cin >> times;
    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete [] ps; // free memory

    ps = buildstr('+', 20); // reuse pointer
    cout << ps << "-DONE-" << ps << endl;
    delete [] ps; // free memory

    return 0;
}

// builds string made of n c characters
// The disadvantage to this kind of design (having a function return a
// pointer to memory allocated by new) is that it makes it the programmer's
// responsibility to remember to use `delete'
char * buildstr(char c, int n)
{
    // to create a string of n visible characters, you need storage for n+1 characters in
    // order to have space for the null character.
    char * pstr = new char[n+1];
    pstr[n] = '\0'; // terminate string

    // the reason for filling the string from back to front instead of
    // front to back is to avoid using an additional variable
    while (n-- > 0) {
        pstr[n] = c; // fill rest of string
    }

    return pstr;
}