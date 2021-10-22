#include <iostream>
#include <array>
#include <string>

std::array<std::string, 10> units = {
  "zero", "jeden", "dwa", "trzy", "cztery", "pięć", "sześć", "siedem", "osiem", "dziewięć"};

std::string to_polish(unsigned value) {
  if (value >= 10U) {
    return "Unable to convert values >= 10";
  }

  return units[value];
}

int main()
{
  unsigned value;
  std::cin >> value;
  std::cout << "Twój polski numer to " << to_polish(value) << '\n';
  return 0;
}
