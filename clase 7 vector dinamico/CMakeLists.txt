cmake_minimum_required(VERSION 3.24)
project(clase_7_vector_dinamico)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Werror -Wconversion)

set(CXXFLAGS "-Wall -Werror -Wconversion")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

add_executable(clase_7_vector_dinamico main.cpp vector.cpp)
