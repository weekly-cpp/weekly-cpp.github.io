#include <iostream>
#include <variant>
#include <string>

int main() {
  std::variant<int, std::string> v;
  v.emplace<0>(7);
  std::cout << std::get<0>(v) << '\n';

  v.emplace<1>("abc");

  std::cout << std::get<1>(v) << '\n';

  std::cout << (v.index() == 1) << '\n';
}
