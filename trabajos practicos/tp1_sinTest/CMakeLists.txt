cmake_minimum_required(VERSION 3.22)
project(inventario)

set(CMAKE_C_STANDARD 23)

add_compile_options(-Wall -Werror -Wconversion)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")
set(CXXFLAGS "-Wall -Werror -Wconversion")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

include_directories(include)
include_directories(src)

add_executable(inventario
        src/Inventario.cpp
        src/Item.cpp
        src/Menu.cpp
        main.cpp
        )

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "inventario.exe")