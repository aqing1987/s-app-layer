// cingolf.cpp -- non-numeric input skipped
// suppose the program finds that the user enters the wrong
// stuff. It needs to take three steps:
// 1. Reset cin to accept new input.
// 2. Get rid of the bad input.
// 3. Prompt the user to try again.
#include <iostream>

const int Max = 5;

int main(int argc, char *argv[])
{
    using namespace std;

    // get data
    int golf[Max];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << Max << " rounds.\n";
    int i;
    for (i = 0; i < Max; i++) {
        cout << "round #" << i+1 << ": ";
        while (!(cin >> golf[i])) {
            cin.clear(); // reset input
            while (cin.get() != '\n') {
                continue; // get rid of bad input
            }
            cout << "Please enter a number: ";
        }
    }

    // calculate average
    double total = 0.0;
    for (i = 0; i < Max; i++) {
        total += golf[i];
    }

    // report results
    cout << total / Max << " = average score "
         << Max << " rounds\n";

    return 0;
}
