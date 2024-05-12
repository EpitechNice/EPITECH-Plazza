cmake_minimum_required(VERSION 3.17)

project(flint)

set(
    CMAKE_CXX_STANDARD 20
)

set(CMAKE_CXX_FLAGS -rdynamic)

add_compile_options(
    -Wall -Wextra -Werror
)

add_library(flint
    SHARED
        src/Colors.cpp
        src/CxxABI.cpp
        src/Exceptions.cpp
        # src/Json.cpp
)

target_include_directories(flint
    PRIVATE
        ./includes/
)
