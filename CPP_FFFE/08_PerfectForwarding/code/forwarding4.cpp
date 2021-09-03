#include <iostream>

template <typename T, typename ... Arguments>
T create(Arguments&& ... arguments)
{
  return T(std::forward<Arguments>(arguments)...);
}

struct BoxOfArgs
{
  BoxOfArgs(int i, std::string s, double d) :i_(i), s_(s), d_(d) {}
  int i_;
  std::string s_;
  double d_;
};

int main()
{
  { // Lvalues:
    int fortytwo = 42;
    int created42 = create<int>(fortytwo);
    std::cout << "From lvalue: " << created42 << '\n';
  }

  { // Rvalues:
    int created42 = create<int>(42);
    std::cout << "From rvalue: " << created42 << '\n';
  }

  { // Perfect forwarding: arbitrary number of arguments!
    int fortytwo = 42;
    std::string s = "this is a string";
    BoxOfArgs box = create<BoxOfArgs>(fortytwo, s, 123.45);
    std::cout << "Box: i=" << box.i_ << ", s=" << box.s_ << ", d=" << box.d_ << '\n';
  }
}
