cmake_minimum_required(VERSION 3.0.0)
project(common-curriculum-selector VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(CCS main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# testing with the single_include versions of Catch2 V2 (in directory catch2)
include(CTest)
add_executable(tests_list test_DS_list.cpp datastructure/list.h)                     #Link List
add_test(NAME TestList COMMAND tests_list)