#include <iostream>
#include <string>
#include <thread>

void run(std::string thread_name) {
  for (int i{0}; i < 10; ++i) {
    // BEGIN CRITICAL SECTION
    std::string output{thread_name + ' ' + std::to_string(i) + '\n'};
    std::cout << output;
    // END CRITICAL SECTION
  }
}

int main()
{
  std::thread thread_1(run, "[A]");
  std::thread thread_2(run, "      [B]");
  thread_1.join();
  thread_2.join();
}
