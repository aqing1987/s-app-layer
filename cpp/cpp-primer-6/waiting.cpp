// waiting.cpp -- using clock() in a time-delay loop
#include <iostream>
#include <ctime> // describes clock() function, clock_t type

int main(int argc, char *argv[])
{
    using namespace std;

    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
    // by calculating the delay time in system units instead of in seconds
    // the program avoids having to convert system time to seconds in each
    // loop cycle.
    clock_t delay = secs * CLOCKS_PER_SEC; // convert to clock ticks
    cout << "starting\a\n";
    clock_t start = clock();

    while (clock() - start < delay) { // wait until time elapses
        ; // note the semicolon
    }

    cout << "done\a\n";

    return 0;
}
