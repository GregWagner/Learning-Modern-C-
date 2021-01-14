/*
 * A program that uses octal and hex representations of unsigned ints.
 * Listing 2-2 Page 33
 */
#include <cstdio>

int main()
{
  unsigned const a {3669732608};
  printf("Yabba %x!\n", a);

  unsigned const b {69};
  printf("There are %u,%o leaves here.\n", b, b);
}
