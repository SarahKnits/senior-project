cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(generic-array-list)

add_executable(generic-array-list generic-array-list.cpp generic-array-list.hpp)

add_definitions("-Wall -Werror")

set_property(TARGET generic-array-list PROPERTY CXX_STANDARD 11)
set_property(TARGET generic-array-list PROPERTY CXX_STANDARD_REQUIRED ON)
