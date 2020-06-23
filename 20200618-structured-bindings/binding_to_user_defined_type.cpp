// g++ -Wall -Wextra -std=c++17 -g binding_to_user_defined_type.cpp -o binding

#include <iostream>
#include <tuple>

namespace weekly_cpp {
class Vector2D
{
  double x_;
  double y_;

public:
  Vector2D() = default;
  Vector2D(double x, double y) : x_{x}, y_{y} {}

  double x() { return x_; }
  double y() { return y_; }

  void operator+=(const Vector2D& rhs) {
    x_ += rhs.x_;
    y_ += rhs.y_;
  }

  template<std::size_t pos>
  double get() {
    if constexpr (pos == 0) {
      return x_;
    }
    if constexpr (pos == 1) {
      return y_;
    }
  }
};

Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs) {
  auto v = lhs;
  v += rhs;
  return v;
}

} // namespace experimental

namespace std {
template<>
class tuple_size<weekly_cpp::Vector2D> : public std::integral_constant<std::size_t, 2> {};

template<std::size_t pos>
class tuple_element<pos, weekly_cpp::Vector2D> {
  static_assert(pos == 0 or pos == 1, "Invalid index!");
public:
  using type = double;
};
} // namespace std

int main() {
  weekly_cpp::Vector2D a = {1.0, 2.0};
  weekly_cpp::Vector2D b = {-1.0, 3.0};
  auto c = a + b;
  std::cout << "vector: " << c.x() << " " << c.y() << '\n';

  auto&& [x, y] = a + b;
  std::cout << "destructured vector: " << x << " " << y << '\n';
}
