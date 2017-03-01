// static.cpp -- using a static local variable
#include <iostream>

// constants
const int ArSize = 10;

// function prototype
void strcount(const char * str);

int main(int argc, char *argv[])
{
    using namespace std;

    char input[ArSize];
    char next;

    cout << "Enter a line:\n";
    // reads up to the end of the line or up to ArSize - 1 characters
    // it leaves the newline character in the input queue
    // attempting to read an empty line with get(char *, int) causes cin
    // to test as false
    cin.get(input, ArSize);
    while (cin) {
        cin.get(next);

        // if next isn't a newline character, there are more characters
        // left on the line. then reject the rest of the line
        while (next != '\n') { // string didn't fit, dispose of remainder
            cin.get(next);
        }

        // if next is a newline character, then the preceding call to
        // cin.get(input, ArSize) must have read the whole line.
        strcount(input);

        cout << "Entert next line (empty line to quit):\n";
        cin.get(input, ArSize);
    }
    cout << "bye\n";

    return 0;
}

/*
 * the automatic variable count is reset to 0 each time the function
 * is called.
 * However, the static variable total is set to 0 once at the beginning.
 * After that, total retains its value between function calls, so it's
 * able to maintain a running total.
 */
void strcount(const char * str)
{
    using namespace std;

    static int total = 0; // static local variable
    int count = 0; // automatic local variable

    cout << "\"" << str << "\" contains ";
    while (*str++) { // go to end of string
        count++;
    }

    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
