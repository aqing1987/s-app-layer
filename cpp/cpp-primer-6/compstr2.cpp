// compstr2.cpp -- comparing strings using string
#include <iostream>
#include <string> // string class

int main(int argc, char *argv[])
{
    using namespace std;

    string word = "?ate";
    // the way the string class overloads the != operator allows you
    // to use it as long as at least one of the operands is a string
    // object; the remaining operand can be either a string object or
    // a C-style string.
    for (char ch = 'a'; word != "mate"; ch++) {
        cout << word << endl;
        word[0] = ch;
    }
    cout << "After loop ends, word is " << word << endl;

    return 0;
}
