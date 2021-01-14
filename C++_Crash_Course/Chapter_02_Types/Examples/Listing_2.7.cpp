/*
 * A program that illustrates the use of logical operators
 * Listing 2-7 Page 40
 */
#include <iostream>

int main()
{
    bool t {true};
    bool f {};

    std::cout << "!true: " << !t << '\n';
    std::cout << "true  &&  false: " << (t && f) << '\n';
    std::cout << "true  && !false: " << (t && !f) << '\n';
    std::cout << "true  ||  false: " << (t || f) << '\n';
    std::cout << "false &&  false: " << (f || f) << '\n';
}
