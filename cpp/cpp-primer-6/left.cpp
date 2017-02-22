// left.cpp -- string function with a default argument
#include <iostream>
#include <cstring>

const int ArSize = 80;

char * left(const char * str, int n = 1);

int main(int argc, char *argv[])
{
    using namespace std;

    char sample[ArSize];
    cout << "Enter a string:\n";
    cin.get(sample, ArSize);

    char *ps = left(sample, 4);
    cout << ps << endl;
    delete [] ps; // free old string

    ps = left(sample);
    cout << ps << endl;
    delete [] ps; // free new string
    return 0;
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string.
char * left(const char * str, int n)
{
    if (n < 0) {
        n = 0;
    }

    // the lesser of n and len
    // This ensures that new doesn't allocate more space than what's
    // needed to hold the string.
    int len = strlen(str);
    n = (n < len) ? n : len;
    char * p = new char[n+1];

#if 0
    int m = 0;
    while (m <= n && str[m]) {
        m++;
    }
    char * p = new char[m+1];
#endif

    int i;
    // if the loop reaches the null character the code is 0 and
    // the loop terminates.
    for (i = 0; i < n && str[i]; i++) {
        p[i] = str[i]; // copy characters
    }

    while (i <= n) {
        p[i++] = '\0'; // set rest of string to '\0
    }

    return p;
}
