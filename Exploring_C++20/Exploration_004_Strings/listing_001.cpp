/*
 * Different styles of string output.
 */
#include <iostream>
#include <string>

int main()
{
    std::string shape {"Triangle"};
    int sides {3};

    std::cout << "Shape\tSides\n" << "-----\t-----\n"
        << "Square\t" << 4 << '\n'
        << "Circle\t?\n"
        << shape << '\t' << sides << '\n';
}

