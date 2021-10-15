cmake_minimum_required(VERSION 3.15)
project(proj)

set(CMAKE_CXX_STANDARD 14)
if(MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-Wextra" "-pedantic" "-g")
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options("-stdlib=libstdc++")
    endif()
endif()

add_executable(proj Nod.cpp Nod.h main.cpp ListaDubluInlantuita.cpp ListaDubluInlantuita.h Lista.cpp Lista.h)

install(TARGETS proj DESTINATION bin)
