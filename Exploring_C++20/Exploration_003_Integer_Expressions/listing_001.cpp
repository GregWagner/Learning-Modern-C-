/*
 * Read the program and determine what the program does.
 * Print nothing if the the input is empty.
 */
#include <iostream>

int main()
{
    int sum {};
    int count {};

    int x;
    while (std::cin >> x) {
        sum += x;
        ++count;
    }
    if (count) {
        std::cout << "Average = "
            << static_cast<double>(sum) /  count << '\n';
    } else {
        std::cout << "No numbers entered\n";
    }
}
