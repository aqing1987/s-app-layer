// strquote.cpp -- different designs
#include <iostream>
#include <string>

using namespace std;

string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2); // has side effect
const string & version3(string & s1, const string & s2); // bad design

int main(int argc, char *argv[])
{
    string input;
    string copy;
    string result;

    cout << "Enter a string: ";
    getline(cin, input);
    copy = input;
    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    result = version2(input, "###");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    cout << "Resetting original string.\n";
    input = copy;
    result = version3(input, "@@@");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
    return 0;
}

// using reference is more efficient because the function doesn't
// have to create new objects and copy data from the old objects
// to the new.
string version1(const string & s1, const string & s2)
{
    string temp;

    temp = s2 + s1 + s2;
    return temp;
}

// has side effect
// it directly alters the original string
const string & version2(string & s1, const string & s2)
{
    s1 = s2 + s1 + s2;
    // safe to return reference passed to function
    return s1;
}

// bad design
// is a reminder of what not to do.
// This function compiles (with a warning), but the program crashes
// when attempting to execute the function.
const string & version3(string & s1, const string & s2)
{
    string temp;

    temp = s2 + s1 + s2;
    // unsafe to return reference to local variable
    return temp;
}