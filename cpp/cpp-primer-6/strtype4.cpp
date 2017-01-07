// strtype4.cpp -- line input

#include <iostream>
#include <string> // make string class available
#include <cstring> // C-style string library

int main(int argc, char *argv[])
{
    using namespace std;

    char charr[20];
    string str;

    // 1. the contents of an uninitialized array are undefined
    // 2. the strlen() function works by starting at the first element
    // of the array and counting bytes until it reaches a null character
    // the first null character appears in uninitialized data is essentially
    // random, so you very well could get a different numeric result using
    // this program
    cout << "Length of string in charr before input: "
         << strlen(charr) << endl;
    // an uninitialized string object is automatically set to zero size
    cout << "Length of string in str before input: "
         << str.size() << endl;

    cout << "Enter a line of text:\n";
    cin.getline(charr, 20); // indicate maximum length
    cout << "You entered: " << charr << endl;
    cout << "Enter another line of text:\n";
    getline(cin, str); // cin now an argument; no length specifier
    cout << "You entered: " << str << endl;
    cout << "Length of string in charr after input: "
         << strlen(charr) << endl;
    cout << "Length of string in str after input: "
         << str.size() << endl;

    return 0;
}
