cmake_minimum_required(VERSION 3.5)
project(bcryptcpp)

add_library(${PROJECT_NAME} src/bcrypt.cpp src/blowfish.cpp src/blf.h src/openbsd.h include/bcrypt.h)
target_include_directories(${PROJECT_NAME} PUBLIC include)