#include <iostream>
#include <string>
#include <thread>

#include <mutex>

std::mutex mtx;
int active_thread_id{0};
const int NUM_CONCURRENT_THREADS{2};

void run(std::string thread_name, int tid) {
  for (int i{0}; i < 10;) {
    const std::lock_guard<std::mutex> lock(mtx);
    if (active_thread_id == tid) {
      // BEGIN CRITICAL SECTION

      if (thread_name == "[A]" && i == 6) {
        i += 1;
        return;
      }
      std::string output{thread_name + ' ' + std::to_string(i) + '\n'};
      std::cout << output;
      active_thread_id = (active_thread_id + 1) % NUM_CONCURRENT_THREADS;
      i += 1;
      // END CRITICAL SECTION
    }
    // mtx is automatically unlocked when lock goes out-of-scope
  }
}

int main()
{
  std::thread thread_a(run, "[A]", 0);
  std::thread thread_b(run, "        [B]", 1);
  thread_a.join();
  thread_b.join();
}
