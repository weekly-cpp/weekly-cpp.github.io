// g++ -Wall -Wextra -std=c++17 -g if_constexpr.cpp -o if_constexpr
#include <iostream>

constexpr int foo(int x) {
  if constexpr (x == 5) {
    return 7;
  } else {
    return 10;
  }
}

int main() {
  std::cout << foo(5);
  return 0;
}
