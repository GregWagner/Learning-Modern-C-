/*
 * An update ClockOfTheLongNow that encapsulates year
 * Listing 2-20 and 2-21 Page 56
 */
#include <iostream>

class ClockOfTheLongNow {
    public:
        void add_year() {
            ++year;
        }

        bool set_year(int new_year) {
            if (new_year < 2019) {
                return false;
            }
            year = new_year;
            return true;
        }

        int get_year() {
            return year;
        }

    private:
        int year;
};

int main()
{
    ClockOfTheLongNow clock;
    if (!clock.set_year(2018)) {
        clock.set_year(2019);
    }

    clock.add_year();
    std::cout << "Year: " << clock.get_year() << '\n';
}
