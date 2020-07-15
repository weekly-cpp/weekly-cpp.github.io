void foo() {}
void bar() {}
void baz() {}

int main(int argc, char** argv) {
  switch (argc) {
  case 0:
  case 1:
    bar();
    break;
  case 2:
    baz();
    // [[fallthrough]];
  case 3:
    foo();
    break;
  }
}
