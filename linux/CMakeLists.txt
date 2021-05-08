cmake_minimum_required(VERSION 3.5)
project(number)
set(CMAKE_BUILD_TYPE RelWithDebInfo)  # TODO: Set to Release for production
add_definitions(-std=c++14 -Wall -O3 -g)  # TODO: Remove -g debugging info
include_directories(
)
link_directories(
)

add_library(number STATIC
  ../number.cc
)

add_executable(number_main
  ../number_main.cc
)
set_target_properties(number_main PROPERTIES
  COMPILE_FLAGS "-pthread"
)
target_link_libraries(number_main
  number
)

add_executable(number_test
  ../number_test.cc
)
set_target_properties(number_test PROPERTIES
  COMPILE_FLAGS "-pthread"
)
target_link_libraries(number_test
  number
)
add_test(NAME number_test
  COMMAND number_test
)

# TODO: Add code coverage analysis with gcov
