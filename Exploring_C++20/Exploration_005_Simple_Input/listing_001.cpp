/*
 * Demonstrating input and output.
 */
#include <iostream>

int main()
{
    int x;
    std::cout << "Enter a number: ";
    std::cin >> x;

    int y;
    std::cout << "Enter another number: ";
    std::cin >> y;

    std::cout << "The sum of " << x << " and " << y
        << " is " << x + y << '\n';
}
