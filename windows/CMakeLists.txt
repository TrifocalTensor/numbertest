cmake_minimum_required(VERSION 3.5)
project(verbio)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
add_definitions(-std=c++14 -Wall -O3 -g)
set(CMAKE_C_COMPILER "x86_64-w64-mingw32-g++")
set(CMAKE_CXX_COMPILER "x86_64-w64-mingw32-g++")
include_directories(
)
link_directories(
)

add_library(number_win STATIC
  ../number.cc
)

add_executable(number_main_win
  ../number_main.cc
)
set_target_properties(number_main_win PROPERTIES
  COMPILE_FLAGS "-pthread"
)
target_link_libraries(number_main_win
  number_win
)

configure_file(
  /usr/lib/gcc/x86_64-w64-mingw32/9.3-win32/libgcc_s_seh-1.dll
  ${CMAKE_CURRENT_BINARY_DIR}
)
configure_file(
  /usr/lib/gcc/x86_64-w64-mingw32/9.3-win32/libstdc++-6.dll
  ${CMAKE_CURRENT_BINARY_DIR}
)
