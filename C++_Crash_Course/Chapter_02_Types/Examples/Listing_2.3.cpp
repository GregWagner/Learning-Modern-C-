/*
 * Listing 2-3
 * Printing several floating points
 */
#include <cstdio>

int main()
{
  double const an {6.0221409e23};
  printf("Avogadro's Number: %le %lf %lg\n", an, an, an);

  float const hp {9.75};
  printf("Hogwarts' Platform %e %f %g\n", hp, hp, hp);
}
