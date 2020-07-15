#include <iostream>

class Empty {};
struct S1 {
    int x;
    [[no_unique_address]] Empty e;
};

struct S2 { int x; };

struct S3 { int x; Empty e; };

static_assert(sizeof(S1) == sizeof(S2), "beware");

int main() {
  S1 s1;
  S2 s2;
  S3 s3;
  std::cout << sizeof(s1) << ' ' << sizeof(s2) << ' ' << sizeof(s3) << '\n';
}
