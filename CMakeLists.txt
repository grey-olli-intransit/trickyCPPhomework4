cmake_minimum_required(VERSION 3.20)
project(homework4)

set(CMAKE_CXX_STANDARD 20)

add_executable(homework4 main.cpp)
target_include_directories(homework4 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)