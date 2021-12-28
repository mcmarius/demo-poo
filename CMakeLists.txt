cmake_minimum_required(VERSION 3.15)
project(proj)

set(CMAKE_CXX_STANDARD 20)

add_executable(proj Nod.cpp Nod.h main.cpp ListaDubluInlantuita.cpp ListaDubluInlantuita.h Lista.cpp Lista.h)


if(MSVC)
    target_compile_options(proj PRIVATE /W4 /permissive-)
else()
    target_compile_options(proj PRIVATE -Wall -Wextra -pedantic -g)
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        target_compile_options(proj PRIVATE -stdlib=libstdc++)
    endif()
endif()

install(TARGETS proj DESTINATION bin)
