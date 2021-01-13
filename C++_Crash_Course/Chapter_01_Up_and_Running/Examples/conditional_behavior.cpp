/*
 * Listing 1.4
 */
#include <iostream>

int main()
{
  int x {};
  if (x > 0) {
    std::cout << "Positive.\n";
  } else if (x < 0) {
    std::cout << "Negative.\n";
  } else {
    std::cout << "Zero.\n";
  }
}
