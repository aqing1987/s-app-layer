// dowhile.cpp -- exit-condition loop
// sometimes a do-while test does make sense. For example,
// if you're requesting user input, the program has to obtain the
// input before testing it.
#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int n;
    cout << "Enter numberes in the range 1-10 to find ";
    cout << "my favorite number\n";
    do {
        cin >> n; // execute body
    } while (n != 7); // then test
    cout << "Yes, 7 is my favorite.\n";

    return 0;
}
