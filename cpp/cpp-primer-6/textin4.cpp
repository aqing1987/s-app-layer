// textin4.cpp -- reading chars with cin.get()
#include <iostream>
#include <cstdio>

int main(int argc, char *argv[])
{
    using namespace std;

    int ch; // should be int, not char
    int count = 0;

    while ((ch = cin.get()) != EOF) { // test for end-of-file
        cout.put(char(ch));
        ++count;
    }
    cout << endl << count << " characters read\n";

    return 0;
}
