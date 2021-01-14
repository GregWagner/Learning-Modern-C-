/*
 * Assigns several character-typed variables and prints them
 * Listing 2.4 Page 38
 */
#include <cstdio>

int main()
{
  char x {'M'};
  wchar_t y {L'Z'};

  printf("Windows binaries start with %c%lc\n", x, y);
}
