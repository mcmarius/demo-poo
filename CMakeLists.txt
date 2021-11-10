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

include(FetchContent)

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        2f11710abc5aa478503a7ff3f9e654bd2078ebab # 2.5.1
)

FetchContent_MakeAvailable(SFML)


add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_SOURCE_DIR}/include)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
