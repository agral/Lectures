/**
 * Name: storing.cpp
 * Description: Demo code for "C++ Friends" meeting #20,
 *              investigating the efficiency of standard C++ containers.
 *              Tests performance of standard containers when storing data.
 * Author: Adam Graliński (adam@gralin.ski)
 * License: MIT
 */

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <chrono>
#include <iostream>

const uint64_t TEST_SIZE {5'000'000};

template <typename T>
void test_storing() {
  std::cout << "Testing " << typeid(T).name() << " ... ";
  auto start {std::chrono::system_clock::now()};
  T container {};
  for (uint64_t i {0}; i < TEST_SIZE; ++i) {
    container.push_back(i);
  }
  auto finish {std::chrono::system_clock::now()};
  auto elapsed {std::chrono::duration_cast<std::chrono::milliseconds>(finish - start)};
  std::cout << "done, took " << elapsed.count() << " ms\n";
}

template <typename T>
void test_storing_insert() {
  std::cout << "Testing " << typeid(T).name() << " ... ";
  auto start {std::chrono::system_clock::now()};
  T container {};
  for (uint64_t i {0}; i < TEST_SIZE; ++i) {
    container.insert(i);
  }
  auto finish {std::chrono::system_clock::now()};
  auto elapsed {std::chrono::duration_cast<std::chrono::milliseconds>(finish - start)};
  std::cout << "done, took " << elapsed.count() << " ms\n";
}

int main()
{
  std::cout << "Storage tests:\n";
  test_storing<std::vector<uint64_t>>();
  test_storing<std::deque<uint64_t>>();
  test_storing<std::list<uint64_t>>();
  test_storing_insert<std::set<uint64_t>>();
  test_storing_insert<std::unordered_set<uint64_t>>();
}
