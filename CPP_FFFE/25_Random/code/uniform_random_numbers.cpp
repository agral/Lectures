#include <iostream>
#include <random>
#include <cstdint>

int main() {
  auto const seed{2022'12'09};
  std::mt19937 urbe{seed};

  // generate random integers in range [0-9]:
  std::uniform_int_distribution<int> dist_int{0, 9};
  for (std::size_t i = 0; i < 10; ++i) {
    auto const random_int = dist_int(urbe);
    std::cout << random_int << " ";
  }
  std::cout << "\n";

  // generate random doubles in range [-2.0 - 3.4567):
  std::uniform_real_distribution<double> dist_double{-2.0, 3.4567};
  for (std::size_t i = 0; i < 5; ++i) {
    auto const random_double = dist_double(urbe);
    std::cout << random_double << " ";
  }
  std::cout << "\n";
}
