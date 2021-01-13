/*
 * Listing 2.4
 * Assigns several character-typed variables and prints them
 */
#include <cstdio>

int main()
{
  char x {'M'};
  wchar_t y {L'Z'};

  printf("Windows binaries start with %c%lc\n", x, y);
}
