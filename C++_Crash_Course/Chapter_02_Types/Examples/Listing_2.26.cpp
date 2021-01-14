/*
 * A class announcing which of its several constructors 
 * gets called during initialization
 * Listing 2-26 and 2-27 Page 62
 */
#include <iostream>

class Taxonomist {
    public:
        Taxonomist() {
            std::cout << "(no argumments)\n";
        }

        Taxonomist(char x) {
            std::cout << "char: " << x << '\n';
        }

        Taxonomist(int x) {
            std::cout << "int: " << x << '\n';
        }

        Taxonomist(float x) {
            std::cout << "float: " << x << '\n';
        }
};

int main()
{
    Taxonomist t1;
    Taxonomist t2 {'c'};
    Taxonomist t3 {65537};
    Taxonomist t4 {6.02e23f};
    Taxonomist t5 ('g');
    Taxonomist t6 = {'l'};
    Taxonomist t7 {};
    Taxonomist t8();     // note: this is actually a function declaration
}
