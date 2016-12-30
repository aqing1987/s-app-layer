// hexoct1.cpp -- shows hex and octal literals

#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int chest = 42; // decimal integer literal
    int waist = 0x42; // hexadecimal interger literal
    int inseam = 042; // octal integer literal

    cout << "Monsieur cuts a striking figure!\n";
    cout << "chest = " << chest << " (42 in deciaml)\n";
    cout << "waist = " << waist << " (0x42 in hex)\n";
    cout << "inseam = " << inseam << " (042 in octal)\n";
    return 0;
}
