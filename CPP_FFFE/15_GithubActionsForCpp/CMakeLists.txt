cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(FriendlyCode)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

include_directories(src)

### Main binary target: FriendlyCode
file(GLOB_RECURSE SRC_SOURCES LIST_DIRECTORIES true
    src/*.hpp
    src/*.cpp
)
include_directories(FriendlyCode ${SDL2_INCLUDE_DIRS})
add_executable(FriendlyCode ${SRC_SOURCES})
target_link_libraries(FriendlyCode ${SDL2_LIBRARIES})

# Necessary so that code from /src/ can be used by files in /test/ directory:
add_library(FriendlyCode_lib STATIC ${SRC_SOURCES})


### Test binary target: test_FriendlyCode
add_subdirectory(lib/googletest)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES true
    test/*.hpp
    test/*.cpp
)
add_test(
    NAME test_FriendlyCode
    COMMAND test_FriendlyCode
)
add_executable(test_FriendlyCode ${TEST_SOURCES})
target_link_libraries(test_FriendlyCode PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
