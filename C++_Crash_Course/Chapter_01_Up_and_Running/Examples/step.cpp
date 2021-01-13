/*
 * A step function that returns -1 for negative values, 0 
 * for zero, and 1 for positive values.
 * Listing 1-8 page 20
 */
#include <iostream>

int step_function(int x)
{
  int result {};
  if (x < 0) {
    result = -1;
  } else if (x > 0) {
    result = 1;
  }
  return result;
}

int main()
{
  int const FIRST {42};
  int const SECOND {-32767};

  int num1 {FIRST};
  int result1 = step_function(num1);

  int num2 {};
  int result2 = step_function(num2);

  int num3 {SECOND};
  int result3 = step_function(num3);

  std::cout << "Num1: " << num1 << ", Step: " << result1 << '\n';
  std::cout << "Num2: " << num2 << ", Step: " << result2 << '\n';
  std::cout << "Num3: " << num3 << ", Step: " << result3 << '\n';
}
