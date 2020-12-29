/*
 * STL Algorithms can take a callable object and call it on elements
 * of the input container. In C++ 98/03, this only included pointers
 * or class types with the call operator (commonly refered to as
 * "functor")
 *
 * This is why we need lambdas
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

// regualr function that can be used as a callable
void printFunc(int x)
{
    std::cout << x << '\n';
}

// class with a call operator
class Printer {
    public:
        // you can call this object like a regular function
        void operator()(int x) const {
            std::cout << x << '\n';
        }
};

// Function object with state
class PrinterEx {
    public:
        PrinterEx(): numCalls(0) {}
        PrinterEx(std::string const &str): msg(str), numCalls(0) {};

        void operator()(int x) {
            std::cout << msg << x << '\n';
            ++numCalls;
        }

        std::string msg;
        int numCalls;
};

int main()
{
    std::vector<int> v;
    v.push_back(1);     // no uniformm initialzation in C++03
    v.push_back(2);

    // using a regular function
    std::for_each(v.begin(), v.end(), printFunc);

    // using a class that overrides the call operator
    std::for_each(v.begin(), v.end(), Printer());

    // using a class that overrides the call operator and has state
    const PrinterEx vis = std::for_each(v.begin(), v.end(),
            PrinterEx());
    std::cout << "Number of calls: " << vis.numCalls << '\n';

    // example of capturing a variable
    std::string const introText("Element: ");
    const PrinterEx vis1 = std::for_each(v.begin(), v.end(),
            PrinterEx(introText));
    std::cout << "Number of calls: " << vis1.numCalls << '\n';

    for (auto i {3}; i <= 9; ++i) {
        v.push_back(i);
    }

    // Using old C++98/03 functional helpers
    const size_t smaller5 = std::count_if(v.begin(), v.end(),
            std::bind2nd(std::less<int>(), 5));
    std::cout << "Count of smaller than 5 values: " << smaller5 << '\n';

    // Composing functional helpers
    using std::placeholders::_1;
    std::vector<int> v1;
    for (int i {}; i <= 9; ++i) {
        v1.push_back(i);
    }
    // this works, but it is complicated and not natural
    const size_t val = std::count_if(v1.begin(), v1.end(),
                std::bind(std::logical_and<bool>(),
                    std::bind(std::greater<int>(), _1, 2),
                    std::bind(std::less_equal<int>(), _1, 6)));
    std::cout << "Counted value (2 < x <= 6): " << val << '\n';

}
