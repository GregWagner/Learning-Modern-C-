/*
 * A program that indexes into an array.
 * Listing 2-9 Page 43
 */
#include <iostream>

int main()
{
    int arr[] = {1, 2, 3, 4};
    std::cout << "The third element is " << arr[2] << '\n';

    arr[2] = 100;
    std::cout << "The third element is " << arr[2] << '\n';
}
