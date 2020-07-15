#include <iostream>
#include <vector>
#include <string>

union Nontrivial {
  std::string str;
  std::vector<int> vec;

  ~Nontrivial() {};
};

void foo() {
  Nontrivial u = { "abc"};
  std::cout << u.str << '\n';
  u.str.~basic_string();
  new (&u.vec) std::vector<int>({1, 2, 3});
  std::cout << u.vec[1] << '\n';
  u.vec.~vector();
}

int main() {
  foo();
}
