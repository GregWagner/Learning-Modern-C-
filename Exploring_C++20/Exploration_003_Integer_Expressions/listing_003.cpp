/*
 * Read integers and print a message that tells the user
 * whether the number is even ot odd.
 */
#include <iostream>

int main()
{
    int x;
    while (std::cin >> x) {
        std::cout << x << " is "
            << (x % 2 ? "odd" : "even")
            << ".\n";
    }
}
