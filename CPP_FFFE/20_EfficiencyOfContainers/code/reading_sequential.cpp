/**
 * Name: reading_sequential.cpp
 * Description: Demo code for "C++ Friends" meeting #20,
 *              investigating the efficiency of standard C++ containers.
 *              Tests performance of standard containers
 *              when accessing data sequentially, that is: from begin to end.
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

using tested_type = uint64_t;

const std::size_t NUM_SEQUENTIAL_READS {1'000};
const std::size_t CONTAINER_SIZE {1000};

void test_list() {
  std::list<tested_type> container{};
  for (std::size_t i {0}; i < CONTAINER_SIZE; ++i) {
    container.push_back(i);
  }
  std::cout << "Testing std::list ... " << std::flush;
  tested_type read_value;
  auto start {std::chrono::system_clock::now()};
  for (std::size_t s {0}; s < NUM_SEQUENTIAL_READS; s++) {
    // begin s-th sequential read
    for (std::size_t r {0}; r < CONTAINER_SIZE; r++) {
      // read r-th element of the container (a list)
      auto it = container.cbegin();
      std::advance(it, r);
      read_value = *it;
    }
  }
  auto finish {std::chrono::system_clock::now()};
  auto elapsed {std::chrono::duration_cast<std::chrono::milliseconds>(finish - start)};
  std::cout << "done, took " << elapsed.count() << " ms\n";
}

template <typename T>
void test_random_access() {
  T container{};
  for (std::size_t i {0}; i < CONTAINER_SIZE; i++) {
    container.push_back(i);
  }
  std::cout << "Testing " << typeid(T).name() << " ... " << std::flush;
  tested_type read_value;
  auto start {std::chrono::system_clock::now()};
  for (std::size_t k {0}; k < NUM_SEQUENTIAL_READS; k++) {
    // begin s-th sequential read
    for (std::size_t r {0}; r < CONTAINER_SIZE; r++) {
      // read r-th element of the container (a deque or a vector)
      read_value = *(container.cbegin() + r);
    }
  }
  auto finish {std::chrono::system_clock::now()};
  auto elapsed {std::chrono::duration_cast<std::chrono::milliseconds>(finish - start)};
  std::cout << "done, took " << elapsed.count() << " ms\n";
}

template <typename T>
void test_random_access_for_sets() {
  T container{};
  for (std::size_t i {0}; i < CONTAINER_SIZE; i++) {
    container.insert(i);
  }
  std::cout << "Testing " << typeid(T).name() << " ... " << std::flush;
  tested_type read_value;
  auto start {std::chrono::system_clock::now()};
  for (std::size_t s {0}; s < NUM_SEQUENTIAL_READS; s++) {
    // begin s-th sequential read
    for (std::size_t r {0}; r < CONTAINER_SIZE; r++) {
      // read r-th element of the container (a set or an unordered_set)
      read_value = *(container.find(r));
    }
  }
  auto finish {std::chrono::system_clock::now()};
  auto elapsed {std::chrono::duration_cast<std::chrono::milliseconds>(finish - start)};
  std::cout << "done, took " << elapsed.count() << " ms\n";
}

int main()
{
  std::cout << "Sequential read tests:\n";
  test_random_access<std::vector<tested_type>>();
  test_random_access<std::deque<tested_type>>();
  test_list();
  test_random_access_for_sets<std::set<tested_type>>();
  test_random_access_for_sets<std::unordered_set<tested_type>>();
}
