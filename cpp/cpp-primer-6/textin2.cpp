// textin2.cpp -- using cin.get(char)
// the member function cin.get(ch) reads even if it is a space,
// tabs, and newlines
#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    char ch;
    int count = 0; // use basic input
    cout << "Enter characters; enter # to quit:\n";
    cin.get(ch); // use the cin.get(ch) function
    while (ch != '#') { // test the character
        cout << ch; // echo the character
        ++count; // count the character
        cin.get(ch);
    }
    cout << endl << count << " characters read\n";

    return 0;
}
