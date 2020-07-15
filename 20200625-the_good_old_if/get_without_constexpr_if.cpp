#include <iostream>

namespace no_if {
class Vector2D {
  double x_;
  double y_;
  public:
  Vector2D(double x, double y) : x_{x}, y_{y} {}

  template <std::size_t idx> double get();

};

template<> double Vector2D::get<0>() { return x_; }
template<> double Vector2D::get<1>() { return y_; }

}

namespace with_if {
class Vector2D {
  double x_;
  double y_;
  public:
  Vector2D(double x, double y) : x_{x}, y_{y} {}

  template <std::size_t idx> double get() {
    if constexpr (idx == 0) return x_;
    if constexpr (idx == 1) return y_;
  }
};
}

int main() {
  no_if::Vector2D v{1.0, 3.0};
  with_if::Vector2D w{7.1, 3.6};
  std::cout << "v: { x:" << v.get<0>() << " y:" << v.get<1>() << " }\n";
  std::cout << "w: { x:" << w.get<0>() << " y:" << w.get<1>() << " }\n";
}
