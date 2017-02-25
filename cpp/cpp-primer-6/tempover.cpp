// tempover.cpp -- template overloading
// If you remove Template B from the program, the compiler then
// uses Template A for listing the contents of pd, so it lists the
// addresses instead of the values.
// In short, the overload resolution process looks for a function that's
// the best match.
#include <iostream>

//#define ENABLE_TEMPLATE_B

template <typename T> // template A
void ShowArray(T arr[], int n);

#ifdef ENABLE_TEMPLATE_B
// Template B is the more specialized because it makes
// the specific assumption that the array contents are pointers.
template <typename T> // template B
void ShowArray(T * arr[], int n);
#endif

struct debts
{
    char name[50];
    double amount;
};

int main(int argc, char *argv[])
{
    using namespace std;

    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] = {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0},
    };
    double * pd[3];

    // set pointers to the amount members of the structure in mr_E
    for (int i = 0; i < 3; i++) {
        pd[i] = &mr_E[i].amount;
    }

    cout << "Listing Mr. E's counts of things:\n";
    // things is an array of int
    ShowArray(things, 6); // uses template A
    cout << "Listing Mr. E's debts:\n";
    // pd is an array of pointers to double
    ShowArray(pd, 3); // uses template B (more specialized)

    return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    using namespace std;

    cout << "template A\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

#ifdef ENABLE_TEMPLATE_B
template <typename T>
void ShowArray(T * arr[], int n)
{
    using namespace std;

    cout << "template B\n";
    for (int i = 0; i < n; i++) {
        cout << *arr[i] << ' ';
    }
    cout << endl;
}
#endif