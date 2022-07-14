#include <iostream>

struct Fraction {
  int numerator, denominator;
  auto operator<=>(Fraction const &) const = default;
  friend std::ostream & operator<<(std::ostream &, Fraction const &);
};
std::ostream & operator<<(std::ostream & os, Fraction const & f) {
  os << "(" << f.numerator << "/" << f.denominator << ")";
  return os;
}

void change_fraction(Fraction f) {
  f.numerator = 1;
  f.denominator = 2;
  std::cout << "Inside change_fraction, f == " << f << "\n";
}

void make_new_fraction(Fraction& f) {
  f = {8, 13}; // calls Fraction constructor
  std::cout << "Inside make_new_fraction, f == " << f << "\n";
}

int main() {
  Fraction a {3, 5};
  std::cout << "Before change_fraction, a == " << a << "\n";
  change_fraction(a);
  std::cout << "After change_fraction, a == " << a << "\n\n";

  std::cout << "Before make_new_fraction, a == " << a << "\n";
  make_new_fraction(a);
  std::cout << "After make_new_fraction, a == " << a << "\n";
}
