/*
 * Create a function called absolute_value that returns the absolute
 * value of its single argment. The absolute value of an inteer x is
 * the following: x (itself) if x is greater than or equal to 0; otherwise,
 * it is x times -1.
 */
#include <iostream>

int absolute_value(int x)
{
  return (x >= 0 ? x : x * -1);
}

int main()
{
  int const NUM {-10};
  std::cout <<  "The absolute value of " << NUM << " is " <<
      absolute_value(NUM) << ".\n";
}
