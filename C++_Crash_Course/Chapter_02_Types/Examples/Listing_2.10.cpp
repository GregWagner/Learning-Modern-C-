/*
 * Listing 2-10
 */
#include <cstdio>
#include <cstddef>

int main()
{
  unsigned long maximum {};
  unsigned long const values[] {10, 50, 20, 40, 0};

  for (size_t i {}; i < 5; ++i) {
    if (values[i] > maximum) {
      maximum = values[i];
    }
  }
  printf("The maximum value is %lu\n.", maximum);
}
