/*
 * Printing the letters of the alphabet in lowercase
 * and upper case using ASCII
 * Listing 2-12 Page 49
 */
#include <cstdio>

int main()
{
    char alphabet[27];

    for (int i {}; i < 26; ++i) {
        alphabet[i] = i + 'a';
    }
    alphabet[26] = 0;

    printf("%s\n", alphabet);

    for (int i {}; i < 26; ++i) {
        alphabet[i] = i + 'A';
    }
    printf("%s\n", alphabet);
}
