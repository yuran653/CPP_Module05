#include <iostream>
#include <exception>

struct MyException : std::exception {
  const char* what() const throw() {
    return "Division by zero from what()";
  }
};

int main() {
  int x = 10;
  int y = 0;

  try {
    if (y == 0)
      throw MyException();

    int result = x / y;
    std::cout << result << std::endl;

  } catch (const std::exception& e) {
    std::cerr << "An exception occurred: " << e.what() << std::endl;
  }

  return 0;
}
