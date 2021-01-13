/*
 * Exercise 1-4
 * Write another function called sum that takes two int arguments and
 * returns their sum.
 */
#include <iostream>

int sum(int a, int b)
{
  return a + b;
}

int main()
{
  int const x {5};
  int const y {7};

  std::cout << "The sum of " << x << " and " << y << " is " <<
    sum(x, y) << ".\n";
}
