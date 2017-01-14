// equal.cpp -- equality VS assignment
#include <iostream>

int main(int argc, char *argv[])
{
    using namespace std;

    int quizscores[10] = {
        20, 20, 20, 20, 20, 19, 20, 18, 20, 20
    };

    cout << "Doing it right:\n";
    int i;
    for (i = 0; quizscores[i] == 20; i++) {
        cout << "quize " << i << " is a 20\n";
    }
    // warning: you may prefer reading about this program
    // to actually running it.
    cout << "Doing it dangerously wrong: \n";
    for (i = 0; quizscores[i] = 20; i++) {
        cout << "quize " << i << " is a 20\n";
    }

    return 0;
}
