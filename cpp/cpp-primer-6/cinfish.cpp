// cinfish.cpp -- non-numeric input terminates loop
#include <iostream>

const int Max = 5;

int main(int argc, char *argv[])
{
    using namespace std;

    double fish[Max];
    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << Max
         << " fish <q to terminate>.\n";

    cout << "fish #1: ";
    int i = 0;
    // C++ doesn't evaluate the right side of a logical AND expression if
    // the left side is false.
    // Either bad input or the EOF can cause cin to return false
    while (i < Max && cin >> fish[i]) {
        if (++i < Max) {
            cout << "fish #" << i+1 << ": ";
        }
    }

    // calculate average
    double total = 0.0;
    for (int j = 0; j < i; j++) {
        total += fish[j];
    }
    // report results
    if (i == 0) {
        cout << "No fish\n";
    }
    else {
        cout << total / i << " = averae weight of "
             << i << " fish\n";
    }
    cout << "Done.\n";

    return 0;
}
