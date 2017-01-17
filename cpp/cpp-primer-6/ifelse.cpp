// ifelse.cpp -- using the if else statement
#include <iostream>

int main(int argc, char *argv[])
{
    char ch;

    std::cout << "Type, and I shall repeat.\n";
    std::cin.get(ch);
    while (ch != '.') {
        if (ch == '\n') {
            std::cout << ch; // do if newline
        }
        else {
            // try ch + 1 instead of ++ch for interesting effect
            //std::cout << ch + 1;
            std::cout << ++ch; // do otherwise
        }

        std::cin.get(ch);
    }

    std::cout << "\nPlease execuse the slight confusion.\n";

    return 0;
}
