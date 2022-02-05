cmake_minimum_required(VERSION 3.15)

# NOTE: update executable name in .github/workflows/cmake.yml when changing executable name in this file
# for now, the project name is used as the executable name
project(demo-sfml)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        2888d9c56eba4dedb93a84a3c57957e4a907d428 # master as of 2021-11-18
)

FetchContent_MakeAvailable(SFML)

# NOTE: update executable name in .github/workflows/cmake.yml when changing name here
add_executable(${PROJECT_NAME} main.cpp SomeClass.cpp)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -g -Werror)

    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        target_compile_options(${PROJECT_NAME} PRIVATE -stdlib=libstdc++)
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
        target_compile_options(${PROJECT_NAME} PRIVATE -stdlib=libc++)
    endif()
endif()

# sanitizers
#if(APPLE)
#    # first check Apple since Apple is also a kind of Unix
#    target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
#    target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
#elseif(UNIX)
#    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
##        target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
##        target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
#    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
#        target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=memory,undefined)
#        target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=memory,undefined)
#    endif()
#endif()

# use system so clang-tidy does not report warnings from these folders
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${SFML_SOURCE_DIR}/include)
target_link_directories(${PROJECT_NAME} PRIVATE ${SFML_BINARY_DIR}/lib)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
