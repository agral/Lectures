#include <iostream>

struct Fraction {
  int numerator, denominator;
  auto operator<=>(Fraction const &) const = default;
};

int main() {
  Fraction a {3, 5};
  Fraction b {a};
  a.numerator = 0;
  std::cout << (a != b ? "value" : "reference")
    << " semantics for classes\n";
}
