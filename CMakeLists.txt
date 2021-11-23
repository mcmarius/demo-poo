cmake_minimum_required(VERSION 3.15)
project(demo-bcrypt-cpp)

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
  bcryptcpp
  GIT_REPOSITORY https://github.com/zackartz/Bcrypt.cpp.git
  GIT_TAG        168e7ab62f00586ad8e515a8b4330d715fc6f764 # master as of 2021-11-23
)

FetchContent_GetProperties(bcryptcpp)
if(NOT bcryptcpp_POPULATED)
  FetchContent_Populate(bcryptcpp)

  # Copy an additional/replacement file into the populated source
  # only available in cmake 3.21 :(
  # file(COPY_FILE CMakeLists.bcryptcpp.txt DESTINATION ${bcryptcpp_SOURCE_DIR}/CMakeLists.txt)
  file(REMOVE ${bcryptcpp_SOURCE_DIR}/CMakeLists.txt)
  file(COPY CMakeLists.bcryptcpp.txt DESTINATION ${bcryptcpp_SOURCE_DIR})
  file(RENAME ${bcryptcpp_SOURCE_DIR}/CMakeLists.bcryptcpp.txt ${bcryptcpp_SOURCE_DIR}/CMakeLists.txt)

  add_subdirectory(${bcryptcpp_SOURCE_DIR} ${bcryptcpp_BINARY_DIR})
endif()

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${bcryptcpp_SOURCE_DIR}/include)
target_link_directories(${PROJECT_NAME} PRIVATE ${bcryptcpp_BINARY_DIR}/lib)
target_link_libraries(${PROJECT_NAME} bcryptcpp)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
