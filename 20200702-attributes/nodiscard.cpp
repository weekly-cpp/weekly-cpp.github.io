#include <iostream>

int [[nodiscard]] foo() {
  return 7;
}

int main() {
  foo();
  std::cout << "Bye bye\n";
}
