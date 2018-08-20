/*
 * It's bonus time in the big city! The fatcats are rubbing their paws in
 * anticipation... but who is going to make the most money?
 *
 * Build a function that takes in two arguments (salary, bonus). Salary will
 * be an integer, and bonus a boolean.
 *
 * If bonus is true, the salary should be multiplied by 10. If bonus is false,
 * the fatcat did not make enough money and must receive only his stated salary.
 *
 * Return the total figure the individual will receive as a string prefixed
 * with "£" (= "\u00A3", JS and Java) or "$" (C#, C++, Ruby, Clojure, Elixir,
 * PHP and Python, Haskell).
 *
 * */

#include <iostream>
#include <string>

using namespace std;

// better solution
string bonus_time1(int salary, bool bonus) {
  return "$" + to_string(salary) + (bonus ? "0" : "");
}

string bonus_time(int salary, bool bonus) {
  string out = "$";

  if (bonus)
    out.append(to_string(salary*10));
  else
    out.append(to_string(salary));

  return out;
}

int main() {
  cout << bonus_time1(10000, true) << endl;
  return 0;
}