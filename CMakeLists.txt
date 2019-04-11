cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(untitled main.cpp classes/Polynomial.cpp classes/Polynomial.h classes/QuotientOfPolynomials.cpp classes/QuotientOfPolynomials.h classes/Pool.cpp classes/Pool.h tests/test_Polynomial.cpp tests/test_QuotientOfPolynomials.cpp tests/test_Pool.cpp classes/Function.h tests/test_Function.cpp tests/test_Function.h classes/List.cpp classes/List.h tests/test_List.cpp tests/test_List.h)