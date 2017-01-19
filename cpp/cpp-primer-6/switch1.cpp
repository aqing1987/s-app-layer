// switch1.cpp -- using the switch statement

#include <iostream>

using namespace std;

void showmenu(); // function prototypes
void report();
void comfort();

int main(int argc, char *argv[])
{
    showmenu();

    char choice;
    cin >> choice;
    while (choice != 'Q' && choice != 'q') {
        switch (choice) {
        case 'a':
        case 'A':
            cout << "\a\n";
            break;
        case 'r':
        case 'R':
            report();
            break;
        case 'l':
        case 'L':
            cout << "The boss was in all day.\n";
            break;
        case 'c':
        case 'C':
            comfort();
            break;

        default:
            cout << "That's not a choice.\n";
        }

        showmenu();
        cin >> choice;
    }
    cout << "Bye!\n";

    return 0;
}

void showmenu()
{
    cout << "Plese enter a, r, l, c or q:\n"
        "a) alarm r) report\n"
        "l) alibi c) comfort\n"
        "q) quit\n";
}

void report()
{
    cout << "It's been an excellent week for business.\n"
        "Sales are up 120%. Expenses are down 35%.\n";
}

void comfort()
{
    cout << "Your employees think you are the finest CEO\n"
        "in the industry. The board of directors think\n"
        "you are the finest CEO in the industry.\n";
}
