/*
 * Example using the POD type Book to read and write members.
 * Liisting 2-16 Page 53
 */
#include <iostream>

struct Book {
    char name[256];
    int year;
    int pages;
    bool hardcovert;
};

int main()
{
    Book neuromancer {};
    neuromancer.pages = 271;
    std::cout << "Neuromancer has " << neuromancer.pages << " pages.\n";
}
