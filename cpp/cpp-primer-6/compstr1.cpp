// compstr1.cpp -- comparing strings using arrays
#include <iostream>
#include <cstring> // prototype for strcmp()

int main(int argc, char *argv[])
{
    using namespace std;

    char word[5] = "?ate";
    // strcmp(word, "mate") != 0 // strings are not the same
    // type char really is an integer type
    for (char ch = 'a'; strcmp(word, "mate"); ch++) {
        cout << word << endl;
        word[0] = ch;
    }

    cout << "After loop ends, word is " << word << endl;

    return 0;
}
