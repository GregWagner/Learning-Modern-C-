/*
 * A program using a class
 * Listing 2-19 Page 55
 */
#include <iostream>

class ClockOfTheLongNow {
    public:
        void add_year() {
            ++year;
        }

        int year;
};

int main()
{
    ClockOfTheLongNow clock;
    clock.year = 2017;

    clock.add_year();
    std::cout << "Year: " << clock.year << '\n';

    clock.add_year();
    std::cout << "Year: " << clock.year << '\n';
}
