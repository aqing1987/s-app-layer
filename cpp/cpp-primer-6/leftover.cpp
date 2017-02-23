// leftover.cpp -- overloading the left() function
// You should reserve function overloading for functions that perform
// basically the same task but with different forms of data.
#include <iostream>

unsigned long left(unsigned long num, unsigned ct);
char * left(const char * str, int n = 1);

int main(int argc, char *argv[])
{
    using namespace std;

    char * trip = "Hawaii!!"; // test value
    unsigned long n = 12345678;
    int i;
    char * temp;

    for (i = 1; i < 10; i++) {
        cout << left(n, i) << endl;
        temp = left(trip, i);
        cout << temp << endl;
        delete [] temp; // point to temporary storage
    }
    return 0;
}

// This function returns the first ct digits of the number num
unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;

    if (ct == 0 || num == 0) {
        return 0; // return 0 if no digits
    }

    while (n /= 10) {
        digits++;
    }

    if (digits > ct) {
        ct = digits - ct;
        while (ct--) {
            num /= 10;
        }

        return num; // return left ct digits
    }
    else {
        return num; // if ct >= number of digits return the whole number
    }
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string.
char * left(const char * str, int n)
{
    if (n < 0) {
        n = 0;
    }

    int m = 0;
    while (m < n && str[m]) {
        m++;
    }
    char * p = new char[m+1];

    int i;
    for (i = 0; i < m; i++) {
        p[i] = str[i]; // copy characters
    }
    p[m] = '\0';

    return p;
}
