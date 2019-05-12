cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(frf main.cpp classes/Polynomial.cpp classes/Polynomial.h classes/Quotient.cpp classes/Quotient.h tests/test_Polynomial.cpp tests/test_Quotient.cpp classes/Function.h tests/test_Function.cpp tests/test_Function.h classes/List.cpp classes/List.h tests/test_List.cpp tests/test_List.h classes/Counter.cpp classes/Counter.h lib/c_interface.h lib/c_interface.cpp tests/test_c_interface.cpp tests/test_c_interface.h)
add_library(mylib SHARED lib/c_interface.h lib/c_interface.cpp classes/Polynomial.cpp classes/Polynomial.h classes/Quotient.cpp classes/Quotient.h classes/Function.h classes/List.cpp classes/List.h classes/Counter.cpp classes/Counter.h )