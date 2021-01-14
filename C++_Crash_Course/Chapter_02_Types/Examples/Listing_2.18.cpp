/*
 * A program using the union Variant
 * Listing 2-18 Page 54
 */
#include <iostream>

union Variant {
    char string[10];
    int integer;
    double floating_point;
};

int main()
{
    Variant v;
    v.integer = 42;
    std::cout << "The ulltimate answer: " << v.integer << '\n';

    v.floating_point = 2.7182818284;
    std::cout << "Euler's number e: " << v.floating_point << '\n';

    // You need to keep track of which interpretation is valid
    std::cout << "A dumpster fire: " << v.integer << '\n';
}
