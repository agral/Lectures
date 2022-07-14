#include <iostream>
#include <vector>

int main() {
  std::vector a{0, 1, 2, 3};
  std::vector b{a};
  a[0] = 101;
  std::cout << (a != b ? "value" : "reference")
    << " semantics for containers\n";
}
