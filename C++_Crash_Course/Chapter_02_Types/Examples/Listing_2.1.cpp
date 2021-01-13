/*
 * Listing 2.1
 * A program that assigns several integer variables and prints them.
 */
#include <cstdio>

int main()
{
  unsigned const short a {0b10101010};              // binary
  printf("%hu\n", a);

  int const b {0123};                               // octal
  printf("%d\n", b);

  unsigned long long const d {0xFFFFFFFFFFFFFFFF};  // hexA
  printf("%llu\n", d);
}
