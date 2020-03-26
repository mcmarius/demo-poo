cmake_minimum_required(VERSION 3.15)
project(sapt5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

add_executable(sapt5 Nod.cpp Nod.h main.cpp ListaDubluInlantuita.cpp ListaDubluInlantuita.h)

