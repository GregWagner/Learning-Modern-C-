/*
 * Listing 3-2
 * Uses the dereference operator to read and write
 */
#include <iostream>

int main()
{
  int gettysburg {};
  int *gettysburg_address = &gettysburg;

  std::cout << "Value to gettysburg_address: " << *gettysburg_address << '\n';
  std::cout << "Gettysburg Address: " << gettysburg_address << '\n';

  *gettysburg_address = 17325;
  std::cout << "Value to gettysburg_address: " << *gettysburg_address << '\n';
  std::cout << "Gettysburg Address: " << gettysburg_address << '\n';
}
