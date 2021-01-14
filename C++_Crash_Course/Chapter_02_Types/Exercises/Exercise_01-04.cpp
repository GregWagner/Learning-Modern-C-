/*
 * Exercise 2-1 Page 64
 * Creete an enum class Operation that has values Add, Stubtract, 
 * Multiply, and Divide.
 *
 * Exersie 2-2
 * Create a struct Calculator. It should have a single constructor that
 * takes an Operation.
 *
 * Exercise 2-3
 * Create a method on Calculator called int calculate(int a, int b).
 * Upon invocation, this method should perform addition, subtraction, 
 * multiplication or division based on its constructor argument and
 * return the result.
 */
#include <cstdio>

enum class Operation {
  Add, Subtract, Multiply, Divide,
};

class Calculator {
  public:
    explicit Calculator(Operation op) :op(op) {}

    int calculate(int a, int b) {
      switch(op) {
        case Operation::Add:
          return a + b;
        case Operation::Subtract:
          return a - b;
        case Operation::Multiply:
          return a * b;
        case Operation::Divide:
          return a / b;
        default:
          return 0;
      }
    }

  private:
    Operation op;
};

int main()
{
  Calculator calc{Operation::Subtract};
  printf("%d - %d = %d\n", 40, 12, calc.calculate(40, 12));
}
