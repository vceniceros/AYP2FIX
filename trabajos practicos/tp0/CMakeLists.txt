cmake_minimum_required(VERSION 3.22)
project(fantasma)

set(CMAKE_C_STANDARD 23)

add_compile_options(-Wall -Werror -Wconversion)

set(CXXFLAGS "-Wall -Werror -Wconversion")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

add_executable(fantasma ManipularStrings.cpp fantasma.cpp Menu.cpp
        main.cpp)
