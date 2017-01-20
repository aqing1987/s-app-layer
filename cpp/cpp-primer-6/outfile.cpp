// outfile.cpp -- writing to a file
// these are the main steps for using file output
// 1. Include the fstream header file.
// 2. Create an ofstream object.
// 3. Associate the ofstream object with a file.
// 4. Use the ofstream object in the same manner you would use cout.

#include <iostream>
#include <fstream> // for file I/O

int main(int argc, char *argv[])
{
    using namespace std;

    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile; // create object for output
    outFile.open("carinfo.cscope"); // associate with a file

    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    d_price = 0.913 * a_price;

    // display information on screen with cout
    cout << fixed;
    cout.precision(2); // use a precision of 2 for the display
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;

    // now do exact same thing using outFile instead of cout
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;

    outFile.close(); // done with file

    return 0;
}
