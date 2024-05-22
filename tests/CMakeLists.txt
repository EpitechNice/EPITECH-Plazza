cmake_minimum_required(VERSION 3.20)
project(
    plazza-test
)

set(
    CMAKE_CXX_STANDARD 20
)
set(
    CMAKE_CXX_STANDARD_REQUIRED ON
)

add_compile_options(
    -DDEBUG
)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

enable_testing()

# Windows settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(
    ./../lib/Flint
    ./lib/
)

add_executable(plazza-test
    ../src/Core/Core.cpp
    ../src/Manager/Manager.cpp
    ../src/Kitchen/Kitchen.cpp
    ../src/Chef/Chef.cpp
    ../src/Serveur/Serveur.cpp
    ../src/Parsing/Parsing.cpp
    tests.cpp
)

target_link_libraries(plazza-test PUBLIC
    flint
    GTest::gtest_main
)

target_include_directories(plazza-test PUBLIC
    ../lib/Flint/includes/
    ../includes/
)

include(GoogleTest)
gtest_discover_tests(plazza-test)
