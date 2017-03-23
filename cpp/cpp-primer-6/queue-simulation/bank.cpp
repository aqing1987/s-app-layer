// bank.cpp -- using the Queue interface
// compile with queue.cpp
// the ATM simulation
// The program should allow the user to enter three quantities: the maximum
// queue size, the number of hours the program will simulate, and the average
// number of customers per hour.
// The program should use a loop in which each cycle represents one minute.
// During each minute cycle, the program should do the following:
// 1. determine whether a new customer has arrived. If so, add the customer to
//    the queue if there is room; otherwise, turn the customer away.
// 2. If no one is being processed, take the first person from the queue.
//    Determine how long the person has been waiting and set a wait_time counter
//    to the processing time that the new customer will need.
// 3. If a customer is being processed, decrease the wait_time counter by one
//    minute.
// 4. Track various quantities, such as the number of customers served, the
//    number of customers turned away, cumulative time spent waiting in line,
//   and cumulative queue length.

#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

#include "queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main(int argc, char *argv[]) {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::ios_base;

  // setting things up
  std::srand(std::time(0)); // random initializing of rand()

  cout << "Case Study: Bank of Heather Automatic Teller\n";
  cout << "Enter maximum size of queue: ";
  int qs;
  cin >> qs;
  Queue line(qs); // line queue hods up to qs people

  cout << "Enter the number of simulation hours: ";
  int hours; // hours of simulation
  cin >> hours;
  // simulation will run 1 cycle per minute
  long cyclelimit = MIN_PER_HR * hours; // # of cycles

  cout << "Enter the average number of customers per hour: ";
  double perhour; // average # of arrival per hour
  cin >> perhour;
  double min_per_cust; // average time between arrivals
  min_per_cust = MIN_PER_HR / perhour;

  Item temp; // new customer data
  long turnaway = 0; // turned away by full queue
  long customers = 0; // joined the queue
  long served = 0; // served during the simulation
  long sum_line = 0; // cumulative line length
  int wait_time = 0; // time until autoteller is free
  long line_wait = 0; // cumulative time in line

  // running the simulation
  for (int cycle = 0; cycle < cyclelimit; cycle++) {
    if (newcustomer(min_per_cust)) { // have newcomer
      if (line.isfull()) {
        turnaway++;
      } else {
        customers++;
        temp.set(cycle); // cycle = time of arrival
        line.enqueue(temp); // add newcomer to line
      }
    }

    if (wait_time <= 0 && !line.isempty()) {
      line.dequeue(temp); // attend next customers
      wait_time = temp.ptime(); // for wait_time minutes
      line_wait += cycle - temp.when();
      served++;
    }

    if (wait_time > 0)
      wait_time--;

    sum_line += line.queuecount();
  }

  // reporting results
  if (customers > 0) {
    cout << "customers accepted: " << customers << endl;
    cout << " customers served: " << served << endl;
    cout << "   turnaways: " << turnaway << endl;
    cout << "average queue size: ";
    cout.precision(2);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << (double) sum_line / cyclelimit << endl;
    cout << " average wait time: "
         << (double) line_wait / served << " minutes\n";
  } else {
    cout << "No customers!\n";
  }
  cout << "Done!\n";

  return 0;
}

// x= average time, in minutes, between customers
// reutrn value is true if customer shows up this minute
bool newcustomer(double x) {
  return (std::rand() * x / RAND_MAX < 1);
}