#include <iostream>

int main() {
  int x{};
  std::cin >> x;

  if (x > 0) [[likely]] {
    std::cout << "likely\n";
  } else {
    std::cout << "unlikely\n";
  }
}
