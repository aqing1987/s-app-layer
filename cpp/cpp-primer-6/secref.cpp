// secref.cpp -- defining and using a reference
// shows what happens if you try to make a reference change
// allegiance from a rats variable to a bunnies variable
// In short, you can set a reference by an initializing declaration,
// not by assignment
#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int rats = 101;
    int & rodents = rats; // rodents is a reference

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    int bunnies = 50;
    rodents = bunnies; // can we change the reference?
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "bunnies address = " << &bunnies;
    cout << ", rodents address = " << &rodents << endl;
    return 0;
}
