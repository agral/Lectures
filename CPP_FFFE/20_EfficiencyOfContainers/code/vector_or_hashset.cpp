/**
 * Name: vector_or_hashset.cpp
 * Description: Demo code for "C++ Friends" meeting #20,
 *              investigating the efficiency of standard C++ containers.
 *              Tests performance of both a vector and a hashmap for a task of
 *              storing many random integers and then providing a sorted view to that collection.
 * Author: Adam Graliński (adam@gralin.ski)
 * License: MIT
 */

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

using tested_type = uint64_t;
using timing_granularity = std::chrono::microseconds;

const std::size_t CONTAINER_SIZE {10};
std::random_device dev {};
std::mt19937 rng {dev()};
std::uniform_int_distribution<std::mt19937::result_type> dist10G(1, 10'000'000'000);

void test_vector() {
  std::cout << "Testing std::vector ... " << std::flush;
  auto start {std::chrono::system_clock::now()};
  std::vector<tested_type> vec{};
  for (std::size_t i {0}; i < CONTAINER_SIZE; ++i) {
    vec.push_back(dist10G(rng));
  }
  std::sort(std::begin(vec), std::end(vec));
  auto finish {std::chrono::system_clock::now()};
  auto elapsed {std::chrono::duration_cast<timing_granularity>(finish - start)};
  std::cout << "done, took " << elapsed.count() << " units\n";
}

void test_unordered_set() {
  std::cout << "Testing std::unordered_set ... " << std::flush;
  auto start {std::chrono::system_clock::now()};
  std::unordered_set<tested_type> myset{};
  for (std::size_t i {0}; i < CONTAINER_SIZE; ++i) {
    myset.insert(dist10G(rng));
  }
  auto finish {std::chrono::system_clock::now()};
  auto elapsed {std::chrono::duration_cast<timing_granularity>(finish - start)};
  std::cout << "done, took " << elapsed.count() << " units\n";
}

int main()
{
  std::cout << "Tests commence\n";
  test_vector();
  test_unordered_set();
}
