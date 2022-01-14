#include <iostream>

struct IntWrapper {
  IntWrapper(int val) : m_i(val) {}
  int m_i;
  friend std::ostream& operator<<(std::ostream&, const IntWrapper&);
};
std::ostream& operator<<(std::ostream& os, const IntWrapper& iw)
{
  os << "IntWrapper{" << iw.m_i << "}\n";
  return os;
}

struct Accumulator {
  Accumulator(IntWrapper i = 0) : m_value(i) {}

  void accumulate(IntWrapper num)
  {
    m_value.m_i += num.m_i;
  }

  IntWrapper m_value;
};

int main()
{
  auto value = 42;
#ifdef MVP
  Accumulator acc(IntWrapper(value)); // <-- Most vexing parse
  std::cout << acc.m_value;
#endif

#ifdef FIXED_MVP
  std::cout << "Fix #1: brace initialization\n";
  Accumulator acc1a(IntWrapper{value});
  std::cout << acc1a.m_value;
  Accumulator acc1b{IntWrapper(value)};
  std::cout << acc1b.m_value;
  Accumulator acc1c{IntWrapper{value}};
  std::cout << acc1c.m_value;

  std::cout << "\nFix #2: declare the temporary object outside of the function call\n";
  IntWrapper iw(value);
  Accumulator acc2(iw);
  std::cout << acc2.m_value;

  std::cout << "\nFix #3: Add an extra pair of parentheses"
      "\n(somewhat silly, but useful when working with pre-C++11 compilers!)\n";
  Accumulator acc3((IntWrapper(value)));
  std::cout << acc3.m_value;
  // with double parentheses it is impossible to parse it as a declaration of a function. So, no MVP.
#endif
}
