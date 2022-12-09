#include <iostream>
#include <iomanip>
#include <random>

int main() {
  std::random_device rd{};
  std::mt19937 engine{rd()};
  
  double const mu{10};
  double const sigma{0.5};
  auto norm =
    std::normal_distribution<double>{mu, sigma};

  std::cout << std::setprecision(3) << std::fixed;
  for (std::size_t i = 0; i < 20; ++i) {
    std::cout << norm(engine) << "\n";
  }
}
