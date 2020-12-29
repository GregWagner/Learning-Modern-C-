#include <iostream>
#include "boost/format.hpp"

using namespace std;

int main()
{
    std::string firstName;
    std::cout << "Enter your first name: ";
    std::cin >> firstName;

    std::string lastName;
    std::cout << "Enter your surname: ";
    std::cin >> lastName;

    auto formattedName = str(boost::format("%1% %2%"s) %
            firstName % lastName);
    std::cout << "You said your name is " << formattedName << '\n';
}
