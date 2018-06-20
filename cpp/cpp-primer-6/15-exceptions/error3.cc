// using an exception
// A C++ exception is a response to an exceptional circumstance that
// arises while a program is running, such as an attempt to divide by
// zero.
// Handling an exception has three components:
// 1. Throwing an exception
// 2. Catching an exception with a handler
// 3. Using a try block
//
// What happens if a functin throws an exception and there's no try
// block or else no matching handler. By default, the program
// eventually calls the abort() function.

#include <iostream>

// a throw causes a program to back up through the sequence of
// current function calls until it finds the function that contains
// the try block.
// Int this case, the throw passes program control back to main().
// There, the program looks for an exception handler that matches
// the type of exception thrown.
double hmean(double a, double b) {
  if (a == -b)
    throw "bad hmean() arguments: a = -b not allowed";
  return 2.0 * a * b / (a + b);
}

int main(int argc, char *argv[]) {
  double x, y, z;

  std::cout << "Enter two numbers: ";
  while (std::cin >> x >> y) {
    try {
      z = hmean(x, y); 
    } catch (const char* s) {
      // char* s means that this handler matches a thrown exception
      // that is a string.
      std::cout << s << std::endl;
      std::cout << "Enter a new pair of numbers: ";
      continue;
    }
    
    std::cout << "Harmonic mean of " << x << " and " << y
              << " is " << z << std::endl;
    std::cout << "Enter next set of numbers <q to quit>: ";
  }

  std::cout << "Bye!\n";
  return 0;
}

