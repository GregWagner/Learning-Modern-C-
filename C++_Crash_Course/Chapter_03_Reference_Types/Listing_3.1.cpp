/*
 * Listing 3-1
 * A program featuring the address-of operator and a terrible pun
 */
#include <iostream>

int main()
{
  int gettysburg {};
  std::cout << "Gettysburg: " << gettysburg << '\n';
  
  int *gettysburg_address = &gettysburg;
  std::cout << "&Gettysburg: " << gettysburg_address << '\n';
}
