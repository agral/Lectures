cmake_minimum_required (VERSION 3.8)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED true)
project(nan_poisoning)

add_executable(nan_behavior code/nan_behavior.cpp)
add_executable(typical_nan_sources code/typical_nan_sources.cpp)
add_executable(smartwatch code/nan_poisoning_demo.cpp)
