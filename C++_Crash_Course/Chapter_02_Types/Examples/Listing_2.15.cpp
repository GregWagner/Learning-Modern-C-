/*
 *
 * Listing 2-15 Page 51
 */
#include <iostream>

enum class Race {
    Dinan,
    Teklan,
    Ivyn,
    Moiran,
    Camite,
    Julian,
    Aidan,
};

int main()
{
    Race race = Race::Dinan;

    switch (race) {
        case Race::Dinan:
            std::cout << "You work hard.\n";
            break;
        case Race::Teklan:
            std::cout << "You are very strong.\n";
            break;
        case Race::Ivyn:
            std::cout << "You are a great leader.\n";
            break;
        case Race::Moiran:
            std::cout << "My, how versatile you are.\n";
            break;
        case Race::Camite:
            std::cout << "You're incredibly helpful.\n";
            break;
        case Race::Julian:
            std::cout << ".Anything you want!.\n";
            break;
        case Race::Aidan:
            std::cout << "What an enigma.\n";
            break;
        default:
            std::cout << "Error: unknonw race!.\n";
            break;
    }
}
