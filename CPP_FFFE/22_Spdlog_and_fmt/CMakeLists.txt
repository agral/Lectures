cmake_minimum_required(VERSION 3.14)
project(SpdlogDemo LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

find_package(spdlog CONFIG REQUIRED)

add_executable(SpdlogDemo main.cpp)
target_link_libraries(SpdlogDemo PUBLIC fmt::fmt spdlog::spdlog)

add_executable(RotatingLogDemo rotlog.cpp)
target_link_libraries(RotatingLogDemo PUBLIC fmt::fmt spdlog::spdlog)
