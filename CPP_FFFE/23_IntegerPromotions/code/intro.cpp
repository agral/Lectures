#include <iostream>
#include <vector>

template<typename T_LHS, typename T_RHS>
void print_comparison(T_LHS lhs, T_RHS rhs)
{
  std::cout << lhs << " < " << rhs << ": "
    << std::boolalpha << (lhs < rhs) << "\n";
}

int main()
{
  long negative{-123};
  unsigned short positive{123};
  std::size_t unsigned_positive{456};

  print_comparison(negative, positive);           // A
  print_comparison(negative, unsigned_positive);  // B
}
