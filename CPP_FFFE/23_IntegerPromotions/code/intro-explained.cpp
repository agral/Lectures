#include <iostream>
#include <vector>

void explain();

template<typename T_LHS, typename T_RHS>
void print_comparison(T_LHS lhs, T_RHS rhs)
{
  std::cout << lhs << " < " << rhs << ": " << std::boolalpha << (lhs < rhs) << "\n";
}

int main()
{
  long negative{-123};
  unsigned short positive{123};
  std::size_t unsigned_positive{456};

  print_comparison(negative, positive);           // A
  print_comparison(negative, unsigned_positive);  // B

  std::vector<int> numbers {1, 2, 3, 4, 5};
  for (int i = 0; i < numbers.size(); ++i) {
    std::cout << numbers[i] << ", ";
  }
  std::cout << std::endl;
  explain();
}

void explain() {
  std::cout << "-123(long) is " << static_cast<unsigned long>(-123) << "(unsigned long)\n";
}
