/*
 * Example 3 Chapter 2
 * Sizing a pond for happy fish
 */
#include <iostream>
#include <numbers>
#include <cmath>
#include <fmt>

int main()
{
    // 2 square feet of pond surfacce is required for every
    // 6 inches of fish
    double const FISH_FACTOR {2.0 / 0.5};
    double const INCHES_PER_FOOT {12.0};

    double fish_count {};
    std::cout << "Enter the number of fish you want to keep: ";
    std::cin >> fish_count;

    double fish_length {};
    std::cout << "Enter the average fish length in inches:  ";
    std::cin >> fish_length;
    fish_length /= INCHES_PER_FOOT;

    // Calculate the required surfacce area
    double const pond_area {fish_count * fish_length * FISH_FACTOR};

    // Calculate the pond diameter from the area
    double const pond_diameter {2.0 *
        std::sqrt(pond_area / std::numbers::pi)};

    std::cout << std::fmt("Pond diameter required for () fish is () feet.\n",
            fish_count, pond_diameter);
}
