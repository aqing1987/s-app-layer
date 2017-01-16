// textin1.cpp -- reading chars with a while loop
// cin skips over spaces and newline characters.
#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    char ch;
    int count = 0; // use basic input
    cout << "Enter characters; enter # to quit:\n";
    cin >> ch; // get a character
    while (ch != '#') { // test the character
        cout << ch; // echo the character
        ++count; // count the character
        cin >> ch; // get the next character
    }
    cout << endl << count << " characters read\n";

    return 0;
}
