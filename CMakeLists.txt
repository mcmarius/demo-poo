cmake_minimum_required(VERSION 3.15)
project(demo-sfml)

set(CMAKE_CXX_STANDARD 14)
if(MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall" "-Wextra" "-pedantic" "-g")
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options("-stdlib=libstdc++")
    endif()
endif()

find_package(SFML COMPONENTS graphics window system)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_DIR}/include)
target_link_directories(${PROJECT_NAME} PRIVATE ${SFML_DIR}/lib)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
