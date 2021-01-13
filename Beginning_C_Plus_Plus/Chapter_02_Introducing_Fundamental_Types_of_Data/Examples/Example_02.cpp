/*
 * Example 2 Chapter 2
 * Converting distances
 */
#include <iostream>

int main()
{
    unsigned int yards {};
    unsigned int feet {};
    unsigned int inches {};

    std::cout << "Enter a distance as yards, feet, and inches "
        << "with the three values separated by spaces: ";
    std::cin >> yards >> feet >> inches;

    unsigned const FEET_PER_YARD {3};
    unsigned const INCHES_PER_FOOT {12};

    // Convert the distance into inches
    unsigned total_inches = inches + INCHES_PER_FOOT * 
        (yards * FEET_PER_YARD + feet);
    std::cout << "This distance corresponds to "
        << total_inches << " inches.\n";

    // Convert the distance back to yards, feet, and inches
    std::cout << "Enter a distance in inches: ";
    std::cin >> total_inches;

    feet = total_inches / INCHES_PER_FOOT;
    inches = total_inches % INCHES_PER_FOOT;
    yards = feet / FEET_PER_YARD;
    feet %= FEET_PER_YARD;

    std::cout << "This distance corresponds to "
        << yards << " yards, "
        << feet << " feet, "
        << inches << " inches.\n";
}
