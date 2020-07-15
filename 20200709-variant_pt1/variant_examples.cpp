#include <variant>
#include <iostream>

void foo() {
  std::variant<int, int> vv;
  // vv = 7;
  vv.emplace<0>(7);
  std::cout << std::get<0>(vv) << '\n';
}

int main() {
  foo();
}
