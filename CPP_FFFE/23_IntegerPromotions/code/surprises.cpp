#include <limits>
#include <iostream>

int main()
{
  static_assert(sizeof(int) > sizeof(unsigned short));

  unsigned short one = 1;
  unsigned short maxshort = std::numeric_limits<unsigned short>::max();
  unsigned short sum = maxshort + one;

  std::cout << "one == " << one
            << ",\nmaxshort == " << maxshort
            << ",\nsum = maxshort+one = " << sum << "\n";
  if (sum == maxshort + one) {
    std::cout << "As expected!\n";
  }
  else {
    std::cout << "Oh no!\n";
  }
}
