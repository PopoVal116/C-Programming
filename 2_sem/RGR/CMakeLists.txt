cmake_minimum_required(VERSION 3.10) 
project(TriangleNumbers C)

set(CMAKE_C_STANDARD 99) 
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

find_package(cmocka REQUIRED)

add_library(triangle_lib SHARED triangle.c)

add_executable(triangle main.c) 
target_link_libraries(triangle triangle_lib)

add_executable(test_triangle test.c) 
target_link_libraries(test_triangle triangle_lib cmocka)

enable_testing() 
add_test(NAME TriangleTests COMMAND test_triangle)