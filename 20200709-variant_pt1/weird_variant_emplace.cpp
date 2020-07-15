#include <iostream>
#include <variant>

int main() {
  std::variant<int, int> v;
  v.emplace<0>(7);
  std::cout << std::get<0>(v) << '\n';

  v.emplace<1>(42);

  std::cout << std::get<1>(v) << '\n';
}
