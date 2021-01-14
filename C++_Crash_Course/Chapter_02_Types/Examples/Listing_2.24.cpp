/*
 * Various ways to initialize a POD
 * Listing 2-24 Page 60
 */
#include <iostream>

struct PodStrut {
    std::uint64_t a;
    char b[256];
    bool c;
};

int main()
{
    // all fields are initialized to zero
    PodStrut initialized_pos1 {};
    PodStrut initialized_pos2 = {};

    PodStrut initialized_pos3 {42, "Hello"};
    PodStrut initialized_pos4 {42, "Hello", true};
}
