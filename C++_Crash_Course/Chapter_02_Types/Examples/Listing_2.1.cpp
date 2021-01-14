/*
 * A program that assigns several integer variables and prints them.
 * Listing 2.1 Page 33
 */
#include <iostream>

int main()
{
  unsigned const short a {0b10101010};              // binary
  std::cout << a << '\n';

  int const b {0123};                               // octal
  std::cout << b << '\n';

  unsigned long long const d {0xFFFFFFFFFFFFFFFF};  // hex
  std::cout << d << '\n';
}
