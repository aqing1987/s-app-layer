// twofile1.cpp -- variables with external and internal linkage
// to be compiled with twofile2.cpp
#include <iostream>

int tom = 3; // external variable definition
int dick = 30; // external variable definition
static int harry = 300; // static, internal linkage

// function prototype
void remote_access();

int main(int argc, char *argv[])
{
    using namespace std;

    cout << "main() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";

    remote_access();

    return 0;
}
