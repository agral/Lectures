#include <fmt/core.h>
#include <iostream>
#include <string>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h" // for a basic file logger

using fmt::format;

int main() {
  spdlog::info("Rotating logs' demo has started. We're about to write a million log lines.");
  // basic rotating logger:
  try {
    // Create a rotating logger that uses 5 files, 10KiB each:
    auto rotating_logger = spdlog::rotating_logger_mt(
        "rotating_logger", "rotlog/log", 1024 * 10, 5);
    for (unsigned long counter{}; counter < 1'000'000; ++counter) {
      rotating_logger->info(format("Logging for the {:d}. time!", counter));
    }
  }
  catch (const spdlog::spdlog_ex& e) {
    std::cerr << "Failed to initialize basic log: " << e.what() << std::endl;
  }
  spdlog::info("Done! Bye!");
}
