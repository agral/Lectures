/**
 * Name: reading_random.cpp
 * Description: Demo code for "C++ Friends" meeting #20,
 *              investigating the efficiency of standard C++ containers.
 *              Tests performance of standard containers
 *              when accessing data from "random" indices (i.e. non-sequentially).
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

const std::size_t NUM_RANDOM_READS {5'000'000};
const std::size_t CONTAINER_SIZE {100};
constexpr auto INDEX_FIRST_QUARTER {CONTAINER_SIZE / 20};
constexpr auto INDEX_SECOND_QUARTER {CONTAINER_SIZE / 20 + CONTAINER_SIZE / 4 };
constexpr auto INDEX_THIRD_QUARTER {CONTAINER_SIZE / 20 + CONTAINER_SIZE / 2};
constexpr auto INDEX_FOURTH_QUARTER {CONTAINER_SIZE / 20 + 3 * CONTAINER_SIZE / 4};


void test_list() {
  std::list<tested_type> container{};
  for (std::size_t i {0}; i < CONTAINER_SIZE; ++i) {
    container.push_back(i);
  }
  std::cout << "Testing std::list ... " << std::flush;
  tested_type read_value;
  auto start {std::chrono::system_clock::now()};
  for (std::size_t k {0}; k < NUM_RANDOM_READS; k++) {
    {
      auto it = container.cbegin();
      std::advance(it, INDEX_FIRST_QUARTER);
      read_value = *it;
    }
    {
      auto it = container.cbegin();
      std::advance(it, INDEX_SECOND_QUARTER);
      read_value = *it;
    }
    {
      auto it = container.cbegin();
      std::advance(it, INDEX_THIRD_QUARTER);
      read_value = *it;
    }
    {
      auto it = container.cbegin();
      std::advance(it, INDEX_FOURTH_QUARTER);
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
  for (std::size_t k {0}; k < NUM_RANDOM_READS; k++) {
    read_value = *(container.cbegin() + INDEX_FIRST_QUARTER);
    read_value = *(container.cbegin() + INDEX_SECOND_QUARTER);
    read_value = *(container.cbegin() + INDEX_THIRD_QUARTER);
    read_value = *(container.cbegin() + INDEX_FOURTH_QUARTER);
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
  for (std::size_t k {0}; k < NUM_RANDOM_READS; k++) {
    read_value = *(container.find(INDEX_FIRST_QUARTER));
    read_value = *(container.find(INDEX_SECOND_QUARTER));
    read_value = *(container.find(INDEX_THIRD_QUARTER));
    read_value = *(container.find(INDEX_FOURTH_QUARTER));
  }
  auto finish {std::chrono::system_clock::now()};
  auto elapsed {std::chrono::duration_cast<std::chrono::milliseconds>(finish - start)};
  std::cout << "done, took " << elapsed.count() << " ms\n";
}

int main()
{
  std::cout << "Tests commence\n";
  test_random_access<std::vector<tested_type>>();
  test_random_access<std::deque<tested_type>>();
  test_list();
  test_random_access_for_sets<std::set<tested_type>>();
  test_random_access_for_sets<std::unordered_set<tested_type>>();
}
