cmake_minimum_required(VERSION 3.10) 
project(SortStuff)

enable_testing()

set(CMAKE_C_STANDARD 99)

find_package(CMocka REQUIRED) 
include_directories(${CMOCKA_INCLUDE_DIR}) 
include_directories(${CMAKE_SOURCE_DIR})

set(FILES sort.c)

add_library(sort_stuff STATIC ${FILES})

add_executable(test_it test_sort.c) 
target_link_libraries(test_it sort_stuff ${CMOCKA_LIBRARIES})

add_test(NAME MyTests COMMAND test_it)

add_custom_target(run_it COMMAND ${CMAKE_CTEST_COMMAND} -V DEPENDS test_it )