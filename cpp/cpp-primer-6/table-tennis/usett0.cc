// usett0.cc -- using a base class
#include <iostream>

#include "tabtenn0.h"

int main(int argc, char *argv[]) {
  using std::cout;

  // Note that the program uses constructors with C-style string arguments
  // the string class has a constructor with a constr char * parameter,
  // and that constructor is used automatically to create a string object
  // initialized by the C-style string.
  TableTennisPlayer player1("Chuck", "Blizzard", true);
  TableTennisPlayer player2("Tara", "Boomdea", false);

  player1.Name();
  if (player1.HasTable())
    cout << ": has a table.\n";
  else
    cout << ": hasn't a table.\n";

  player2.Name();
  if (player2.HasTable())
    cout << ": has a table.\n";
  else
    cout << ": hasn't a table.\n";

  return 0;
}
