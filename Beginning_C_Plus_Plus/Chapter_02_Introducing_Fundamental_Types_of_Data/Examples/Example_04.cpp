/*
 * Example 4 Chapter 2
 * Using explicit type conversions
 */
#include <iostream>

int main()
{
    const unsigned FEET_PER_YARD {3};
    const unsigned INCHES_PER_FOOT {12};
    const unsigned INCHED_PER_YARD {FEET_PER_YARD * INCHES_PER_FOOT};

    double length {};
    std::cout << "Enter a length in yards as a decimal: ";
    std::cin >> length;

    // Covert the length into yards, feet, and inches
    unsigned yards {static_cast<unsigned>(length)};
    unsigned feet {static_cast<unsigned>((length - yards) * FEET_PER_YARD)};
    unsigned inches {static_cast<unsigned>(length * INCHED_PER_YARD) % INCHES_PER_FOOT};

    std::cout << length << " yards converts to "
        << yards << " yards, "
        << feet << " feet, "
        << inches << " inches.\n";
}
