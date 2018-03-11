// guess.cc: x
// Description: A guessing game where the player guesses the secret number.

#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char *argv[argc]) {
  int random_num, guess;

  // Initialize random seed
  srand(time(NULL));

  // generate random number between 1 and 100
  random_num = rand() % 100 + 1;

  cout << "Guess our number (1 to 100) ";
  do {
    if (!(cin >> guess)) {
      cout << "Please enter only numbers" << endl;
    } else {
      if (random_num < guess)
        cout << "The secret number is lower than " << guess << endl;
      else if (random_num > guess)
        cout << "The secret number is higher than " << guess << endl;
      else
        cout << "You guessed it: " << random_num << endl;
    }
  } while (random_num != guess);

  cout << "random: " << random_num << endl;
  return 0;
}
