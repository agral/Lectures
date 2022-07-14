#include <iostream>

int main()
{
  int a{10};
  int b{a};
  a = 20;
  std::cout << "b == " << b << "\n";
  std::cout << (b == 10 ? "value" : "reference")
      << " semantics for primitives\n";
}
