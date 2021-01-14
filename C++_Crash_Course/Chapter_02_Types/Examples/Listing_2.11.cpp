/*
 * Refatoring Listing 2-10 with a range-based for loop
 * Listing 2-11 Page 44
 */
#include <iostream>

int main()
{
  unsigned long maximum {};
  unsigned long const values[] {10, 50, 20, 40, 0};

  for (auto value : values) {
    if (value > maximum) {
      maximum = value;
    }
  }
  std::cout << "The maximum value is " << maximum << '\n';
}
