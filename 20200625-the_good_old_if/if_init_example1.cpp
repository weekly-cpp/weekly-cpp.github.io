#include <iostream>
#include <string>

int main()
{
  if (std::string name; std::cin >> name) {
    std::cout << "Hello " << name << '\n';
  }

  if (int number; std::cin >> number) {
    std::cout << "You picked: " << number << '\n';
  } else {
    std::cout << "That's not a number!\n";
  }

  return 0;
}
