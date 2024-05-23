cmake_minimum_required(VERSION 3.5)
project(
    plazza
)

set(
    CMAKE_CXX_STANDARD 20
)

set(CMAKE_CXX_FLAGS -rdynamic)

add_compile_options(
    -Wall -Wextra -Werror
)

add_subdirectory(
    ./lib/Flint
)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    ${PROJECT_SOURCE_DIR}/plazza
)

add_executable(plazza
    src/Chef/Chef.cpp
    src/Core/Core.cpp
    src/Kitchen/Kitchen.cpp
    src/Manager/Manager.cpp
    src/Parsing/Parsing.cpp
    src/Protocol/Protocol.cpp
    src/Reception/Reception.cpp
    src/Serveur/Serveur.cpp
    src/Main.cpp
)

target_link_libraries(plazza PUBLIC flint)

target_include_directories(plazza PUBLIC
    ./includes/
    ./lib/Flint/includes/
)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
  ${PROJECT_SOURCE_DIR}/lib/Flint/CMakeFiles/CMakeTmp)

add_custom_command(TARGET plazza
    POST_BUILD
    COMMAND
        cp plazza ${PROJECT_SOURCE_DIR}/plazza
)