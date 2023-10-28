cmake_minimum_required(VERSION 3.0.0)
project(common-curriculum-selector VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# file(COPY test_data/ DESTINATION test_data/)

# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

add_executable(CCS main.cpp datastructure/list.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_VERBOSE_MAKEFILE OFF)

include(CPack)

# testing with the single_include versions of Catch2 V2 (in directory catch2)
include(CTest)
add_executable(tests_list ./datastructure/list.cpp ./test_list.cpp)  #Link List
add_test(NAME TestList COMMAND tests_list)