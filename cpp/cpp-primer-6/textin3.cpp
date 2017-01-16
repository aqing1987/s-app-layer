// textin3.cpp -- reading chars to end of file
// on windows system
//    ll pp<CTRL>+<Z><ENTER>
// on unix and linux system
//    ll pp<CTRL>+<D>
// or ./a.out < filename
#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    char ch;
    int count = 0;
    cin.get(ch); // attempt to read a char
    while (cin.fail() == false) { // test for EOF
        cout << ch; // echo the character
        ++count;
        cin.get(ch); // attempt to read another char
    }
    cout << endl << count << " characters read\n";

    return 0;
}
