/*
 * Reading strings
 */
#include <iostream>
#include <string>

int main()
{
    std::string name {};
    std::cout << "What is your name? ";
    std::cin >> name;

    std::string response {};
    std::cout << "Hello, " << name << ", how are you? ";
    std::cin >> response;

    std::cout << "Goood-bye, " << name << ". I am glad you feel "
        << response << '\n';
}
