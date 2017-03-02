// usenmsp.cpp -- using namespaces
#include <iostream>
#include "namesp.h"

void other(void);
void another(void);

int main(int argc, char *argv[])
{
    // use using declaration
    using debts::Debt; // makes the Debt structure definition available
    using debts::showDebt; // makes the showDebt function available

    Debt golf = {{"Benny", "Goatsniff"}, 120.0};
    showDebt(golf);
    other();
    another();

    return 0;
}

void other(void)
{
    using std::cout;
    using std::endl;

    // import the entire namespace with a using directive
    using namespace debts; // make all debts and pers names available to other()

    Person dg = {"Doodles", "Glister"};
    showPerson(dg);
    cout << endl;
    Debt zippy[3];

    int i;
    for (i = 0; i < 3; i++) {
        getDebt(zippy[i]);
    }

    for (i = 0; i < 3; i++) {
        showDebt(zippy[i]);
    }

    cout << "total debt: $" << sumDebts(zippy, 3) << endl;

    return;
}

void another(void)
{
    // uses a using declaration
    using pers::Person;

    Person collector = {"Milo", "Rightshift"};
    pers::showPerson(collector);
    std::cout << std::endl;
}
