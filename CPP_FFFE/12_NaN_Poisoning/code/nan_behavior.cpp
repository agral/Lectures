#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>

void pretty_print(const std::string& prefix, double value) {
  std::cout << prefix << (std::isnan(value) ? "\033[0;33mNaN\033[0m" : std::to_string(value)) << '\n';
}

void print_binary_representation(const std::string& prefix, double value) {
  uint64_t uval;
  memcpy(&uval, &value, sizeof(value));
  std::cout << prefix << std::hex << uval << std::dec << '\n';
}

int main()
{
  /* C-style NaN, defined in header cmath */
  double c_style_nan = NAN;
  pretty_print("c_style_nan is ", c_style_nan);

  // C++ -style NaN: std::nan() in header cmath
  // Note: [c++11 and above]
  double std_nan_empty = std::nan("");
  double std_nan2 = std::nan("2");
  double std_nan_abc = std::nan("abc");
  pretty_print("std_nan(\"\") is ", std_nan_empty);
  pretty_print("std_nan(\"2\") is ", std_nan2);
  pretty_print("std_nan(\"abc\") is ", std_nan_abc);

  std::cout << "\nExact binary representation (assuming 64-bit doubles):\n";
  print_binary_representation("std::nan(\"2\"): ", std_nan2);
  print_binary_representation("std::nan(\"5\"): ", std::nan("5"));
  print_binary_representation("std::nan(\"abc\"): ", std_nan_abc);

  // NaN from std::numeric_limits (limits header)
  double quiet_nan = std::numeric_limits<double>::quiet_NaN();
  print_binary_representation("Binary representation of a std::numeric_limits<double>::quiet_NaN(): ", quiet_nan);
  std::cout << "Is a quiet NaN equal to itself? "
      << std::boolalpha << (quiet_nan == quiet_nan) << '\n';
}
