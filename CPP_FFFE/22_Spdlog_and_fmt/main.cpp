#include <fmt/core.h>
#include <iostream>
#include <string>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h" // for a basic file logger
#include "spdlog/sinks/stdout_color_sinks.h" // for a console logger

using fmt::format;
using namespace std::literals;

static const auto APP_NAME = "SpdlogDemo"s;
static const auto VERSION = "0.2.2"s;

int main() {
  spdlog::info("Hello and welcome to spdlog!");
  spdlog::info(format("{}, version {} has started.", APP_NAME, VERSION));

#if 0 // type safety:
  spdlog::info(format("{:s}, version {:s} has started.", APP_NAME, VERSION));
#endif

#if 0 // basic logging to a file:
  try {
    auto basic_file_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic_file_logger.txt");
    basic_file_logger->info(format("Logging this to a file: {}", __PRETTY_FUNCTION__));
  }
  catch (const spdlog::spdlog_ex& e) {
    std::cerr << "Failed to initialize basic log: " << e.what() << std::endl;
  }
#endif

#if 0 // cutoff levels:
  try {
    auto console_logger = spdlog::stdout_color_mt("console_logger");
    console_logger->info("Cutoff levels' demo");
    console_logger->set_level(spdlog::level::debug);
    console_logger->debug("I am getting printed");
    console_logger->trace("And I am not...");

    console_logger->set_level(spdlog::level::info);
    console_logger->debug("Now neither of us");
    console_logger->trace("is logged");
  }
  catch (const spdlog::spdlog_ex& e) {
    std::cerr << "Failed to initialize basic log: " << e.what() << std::endl;
  }
#endif
} // main()
