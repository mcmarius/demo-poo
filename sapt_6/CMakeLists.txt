cmake_minimum_required(VERSION 3.15)
project(sapt6)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

add_executable(sapt6 main.cpp Forma.cpp Forma.h Cerc.cpp Cerc.h Dreptunghi.cpp Dreptunghi.h Pătrat.cpp Pătrat.h Triunghi.cpp Triunghi.h test_initial.cpp test_initial.h)

