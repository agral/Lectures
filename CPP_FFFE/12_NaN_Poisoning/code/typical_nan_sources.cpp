#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>

void pretty_print(const std::string& prefix, double value) {
  std::cout << prefix << (std::isnan(value) ? "\033[0;33mNaN\033[0m" : std::to_string(value)) << '\n';
}


int main()
{
  const auto minus_one = -1.0;
  const auto zero = 0.0;
  const auto forty_two = 42.0;
  const auto positive_infinity = std::numeric_limits<double>::infinity();

  // NaN can "spontaneously" occur via the following actions:
  // 1. NaN == inf - inf
  auto nan1 = positive_infinity - positive_infinity;
  pretty_print("inf - inf is ", nan1);

  // 2. 0.0 / 0.0
  auto nan2 = zero / zero;
  pretty_print("0.0 / 0.0 is ", nan2);

  // 3. 0.0 * inf
  auto nan3 = zero * positive_infinity;
  pretty_print("0.0 * inf is ", nan3);

  // 4. Square root of any negative value:
  auto nan4 = std::sqrt(minus_one);
  pretty_print("sqrt(-1) is ", nan4);

  // 5. The logarithm of a negative value:
  auto nan5 = std::log(minus_one);
  pretty_print("log(-1) is ", nan5);

  // 6. The inverse sine / inverse cosine outside of [-1, 1] interval:
  auto nan6 = std::asin(forty_two);
  pretty_print("asin(42) is ", nan6);

  // In some other languages, inf % num or num % 0 where num is any number
  // results in NaN. However,
  // This is not possible in C++ - modulo operator requires int as both operands,
  // and int type does not have an infinity representation:
  /* auto not_nan_a = positive_infinity % 42; */
  // And the result of modular division by 0 is undefined, so this is UB:
  /* auto not_nan_b = 42 % 0; // don't do this */
}
