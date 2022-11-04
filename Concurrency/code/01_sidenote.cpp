#include <iostream>
#include <string>
#include <thread>

void run(std::string thread_name) {
  for (int i{0}; i < 10; ++i) {
    // BEGIN CRITICAL SECTION

    // What is wrong with the following:?
    std::cout << thread_name << ' ' << std::to_string(i) << '\n';
    // END CRITICAL SECTION
  }
}

int main()
{
  std::thread thread_a(run, "[A]");
  std::thread thread_b(run, "        [B]");
  thread_a.join();
  thread_b.join();
}
