cmake_minimum_required(VERSION 3.26)
project(sorting_algorithms C)

set(CMAKE_C_STANDARD 99)

add_executable(sorting_algorithms main.c
        sorting_algorithms.c
        sorting_algorithms.h)
