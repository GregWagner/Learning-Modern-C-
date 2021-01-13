/*
 * Listing 3.11
 * A program illustrating that you cannot reset references.
 */
#include <iostream>

int main()
{
  int original {100};
  int& original_ref = original;
  std::cout << "Original: " << original << '\n';
  std::cout << "Reference: " << original_ref << '\n';

  int new_value {200};
  original_ref = new_value;
  std::cout << "Original: " << original << '\n';       // 200
  std::cout << "New Value: " << new_value << '\n';     // 200 
  std::cout << "Reference: " << original_ref << '\n';  // 200
}
