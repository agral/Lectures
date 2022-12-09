#include <iostream>
#include <random>

int main() {
  std::random_device rd{};
  std::mt19937 engine{rd()};
  
  // Weighted coin - 40% chance of tossing heads,
  // and therefore 60% of coming up tails.
  double const p{0.4};
  auto flip_coin = std::bernoulli_distribution{p};
  for (std::size_t i = 0; i < 10; ++i) {
    if (flip_coin(engine)) {
      std::cout << "H ";
    }
    else {
      std::cout << "T ";
    }
  }
  std::cout << "\n";
}
