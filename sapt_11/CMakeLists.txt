cmake_minimum_required(VERSION 3.15)
project(proj2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

add_executable(s11 main.cpp Account.cpp Account.h Repository.cpp Repository.h Commit.cpp Commit.h NormalAccount.cpp NormalAccount.h OrganizationAccount.cpp OrganizationAccount.h repo_full.cpp repo_full.h)

