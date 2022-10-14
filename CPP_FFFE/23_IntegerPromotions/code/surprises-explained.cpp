#include <limits>
#include <iostream>
int main()
{
  static_assert(sizeof(int) > sizeof(unsigned short));
  unsigned short one = 1;
  unsigned short maxshort =
      std::numeric_limits<unsigned short>::max();
  unsigned short sum = maxshort + one;
  std::cout << "one == " << one
            << ",\nmaxshort == " << maxshort
            << ",\nsum = maxshort+one = " << sum << "\n";
  if (sum == maxshort + one) {
    std::cout << "As expected!\n";
  } else {
    std::cout << "Oh no!\n";
  }
  // Explanation:
  std::cout << "\nReminder: sum = maxshort + one\n";
  std::cout << "sum is: " << sum << "\n";
  std::cout << "(maxshort + one) is: " << maxshort+one << "\n";
  // dear reviewer: note the promotion happening when adding unsigned numbers
}
