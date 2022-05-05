cmake_minimum_required(VERSION 3.15)
project(proj)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(Boost_USE_MULTITHREADED TRUE)

find_package(Boost REQUIRED COMPONENTS system thread log program_options chrono)
find_package(Threads REQUIRED)

option(GITHUB_ACTIONS "Running on GitHub Actions" OFF)

if(UNIX) # Darwin or Linux
    if(APPLE AND NOT GITHUB_ACTIONS)
        # Prefer a homebrew version of OpenSSL over the one in /usr/lib
        file(GLOB OPENSSL_ROOT_DIR /usr/local/Cellar/openssl@3)
        # Prefer the latest (make the latest one first)
        list(REVERSE OPENSSL_ROOT_DIR)
    endif()
endif()

find_package(OpenSSL)

find_package(PostgreSQL)



add_executable(${PROJECT_NAME} Nod.cpp Nod.h main.cpp ListaDubluInlantuita.cpp ListaDubluInlantuita.h Lista.cpp Lista.h)


if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    message("-- configuring clang options")
    if(NOT GITHUB_ACTIONS)
        target_compile_options(${PROJECT_NAME} PRIVATE -arch=x86_64 -DBOOST_LOG_DYN_LINK -Wno-deprecated-declarations)
    else()
        target_compile_options(${PROJECT_NAME} PRIVATE -DBOOST_LOG_DYN_LINK -Wno-deprecated-declarations)
    endif()
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    message("-- configuring gcc options")
    target_compile_options(${PROJECT_NAME} PRIVATE -DBOOST_LOG_DYN_LINK)
endif()

set(CPPRESTSDK_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/libs/cpprestsdk/Release/include CACHE PATH "CPP Rest SDK include dir")
set(PQXX_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/libs/libpqxx/include CACHE PATH "PQXX include dir")

set(HEADER_SEARCH_PATHS ${CPPRESTSDK_INCLUDE_DIR} ${PQXX_INCLUDE_DIR} ${Boost_INCLUDE_DIR} ${OPENSSL_INCLUDE_DIR})

set(CPPRESTSDK_LIB_DIR ${PROJECT_SOURCE_DIR}/libs/cpprestsdk/build.release/Binaries CACHE PATH "CPP Rest SDK lib dir")
set(PQXX_LIB_DIR ${PROJECT_SOURCE_DIR}/libs/libpqxx/build.release/src CACHE PATH "PQXX lib dir")

if(APPLE)
    if(NOT GITHUB_ACTIONS)
        set(OPENSSL_LIBS "/usr/local/Cellar/openssl@3/${OPENSSL_VERSION}/lib/libssl.3.dylib;/usr/local/Cellar/openssl@3/${OPENSSL_VERSION}/lib/libcrypto.3.dylib")
    else()
        set(OPENSSL_LIBS ${OPENSSL_LIBRARIES})
    endif()
    #set(CPPRESTSDK_LIBRARY "${PROJECT_SOURCE_DIR}/libs/cpprestsdk/build.release/Binaries/") #libcpprest.a")
    #set(POSTGRES_LIBRARY "${PROJECT_SOURCE_DIR}/libs/libpqxx/build.release/src/") #libpqxx.a")
    find_package(ZLIB)
    #set(ZIP_LIBRARY_PATH "/usr/local/Cellar/zlib/1.2.11/lib/" CACHE PATH "Zlib library path")

    set(LIBRARIES_SEARCH_PATHS ${Boost_LIBRARY_DIRS} ${CPPRESTSDK_LIBRARY} ${ZIP_LIBRARY_PATH} ${POSTGRES_LIBRARY})
else()
    set(OPENSSL_LIBS "${OPENSSL_LIBRARIES}")
    #set(CPPRESTSDK_LIBRARY "/usr/lib/build.release/Binaries/libcpprest.so")
    #set(POSTGRES_LIBRARY "${PROJECT_SOURCE_DIR}/libs/libpqxx/build.release/src/libpqxx.a")

    set(LIBRARIES_SEARCH_PATHS ${OPENSSL_LIBS} ${Boost_LIBRARY_DIRS})
endif()



#include(FetchContent)
#
#FetchContent_Declare(
#        SomeLib
#        GIT_REPOSITORY https://github.com/<SomeLib>/<SomeLib>.git
#        GIT_TAG        <some_git_hash> # <which tag/branch @ <some_date>>
#)
#
#FetchContent_MakeAvailable(SomeLib)

message("Compiler: ${CMAKE_CXX_COMPILER_ID} version ${CMAKE_CXX_COMPILER_VERSION}")
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)

    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        target_compile_options(${PROJECT_NAME} PRIVATE -stdlib=libstdc++)
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
        target_compile_options(${PROJECT_NAME} PRIVATE -stdlib=libc++)
    endif()
endif()

# sanitizers
# should disable them when releasing executables
if(APPLE)
    # if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    # first check Apple since Apple is also a kind of Unix
    target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
    target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
    # endif()
elseif(UNIX)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
        # we might use this sanitizer on Clang 10 on Linux
        # we cannot mix sanitizers with Valgrind
        # target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
        # target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
        if("${CMAKE_CXX_COMPILER_VERSION}" MATCHES "10.")
            # check leaks on Linux since macOS does not support the leaks sanitizer yet
            # leaks sanitizer seems is enabled by default on Linux (according to docs),
            # so we do not enable it explicitly
            target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
            target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
        else()
            target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=memory,undefined)
            target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=memory,undefined)
        endif()
    endif()
endif()

# use system so clang-tidy does not report warnings from these folders
#target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${<SomeLib>_SOURCE_DIR}/include)
#target_link_directories(${PROJECT_NAME} PRIVATE ${<SomeLib>_BINARY_DIR}/lib)
#target_link_libraries(${PROJECT_NAME} <SomeLib>)

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${HEADER_SEARCH_PATHS})
target_link_directories(${PROJECT_NAME} PRIVATE ${Boost_LIBRARY_DIRS} ${CPPRESTSDK_LIB_DIR} ${PQXX_LIB_DIR})

if (APPLE)
    #target_link_directories(${PROJECT_NAME} PRIVATE ${ZIP_LIBRARY})
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework CoreFoundation")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Security")
    #target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARIES_SEARCH_PATHS})
    if(GITHUB_ACTIONS)
        target_link_directories(${PROJECT_NAME} PRIVATE ${LIBRARIES_SEARCH_PATHS})
    else()
    endif()
    target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENSSL_LIBS} cpprest pqxx PostgreSQL::PostgreSQL ZLIB::ZLIB)
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-W1, -F/Library/Frameworks")
else()
    #target_link_directories(${PROJECT_NAME} PRIVATE ${CPPRESTSDK_LIB_DIR} ${PQXX_LIB_DIR} ${LIBRARIES_SEARCH_PATHS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENSSL_LIBS} cpprest pqxx PostgreSQL::PostgreSQL)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
