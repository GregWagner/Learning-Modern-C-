/*
 * Determining the number of bits in a bool
 */
#include <iostream>
#include <limits>

int main()
{
    // note that "digits" means binary digits (bits)
    std::cout << "bits per bool: "
        << std::numeric_limits<bool>::digits << '\n';
}
