// compensation.cc: x
// Description: A program to decide the best of three methods of compensation

#include <iostream>
using namespace std;

const int kPricePerUnit = 225; // average price of a pair of shoes
const int kWeeklyWage = 600; // current weekly wage - Method 1
const double kSalary = 7.0; // hourly salary - Method 2
const int kHoursPerWeek = 40; // number of hours worked - Method 2
const double kCommission2 = 0.1; // commision - Method 2
const double kCommission3 = 0.2; // commision - Method 3
const int kBonusPerUnit = 20; // bonus - Method 3

int GetInput() {
  int units;

  cout << "Enter number of units sold per week: ";
  if (!(cin >> units)) {
    cout << "Numbers only" << endl;
    return 0;
  } else {
    return units;
  }
}

// always the same $600 per week
void CalcMethod1() {
  cout << "Method 1: " << kWeeklyWage << endl;
}

// a salary of $7.00 per hour plus a 10% commission on sale
void CalcMethod2(int sales) {
  double hour_pay, total_pay, commission;

  hour_pay = kSalary * kHoursPerWeek;
  commission = (sales * kPricePerUnit) * kCommission2;
  total_pay = hour_pay + commission;
  cout << "Method 2: " << total_pay << endl;
}

// no salary, but 20% commissions and $20 for each pair of shoes sold
void CalcMethod3(int sales) {
  int extra;
  double total_pay, commission;

  extra = kBonusPerUnit * sales;
  commission = (sales * kPricePerUnit) * kCommission3;
  total_pay = extra + commission;
  cout << "Method 3: " << total_pay << endl;
}

int main(int argc, char *argv[argc]) {
  int WeeklySales; // our input variable

  WeeklySales = GetInput();
  if (WeeklySales == 0)
    return 0;

  CalcMethod1();
  CalcMethod2(WeeklySales);
  CalcMethod3(WeeklySales);
  return 0;
}
