cmake_minimum_required(VERSION 3.20)
project(perf_lab CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_compile_options(-O3 -march=native -Wall -Wextra)

add_executable(perf_lab src/main.cpp src/matmul.cpp)
target_include_directories(perf_lab PRIVATE include)
