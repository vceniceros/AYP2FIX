cmake_minimum_required(VERSION 3.22)
project(listas)

set(CMAKE_C_STANDARD 23)

add_compile_options(-Wall -Werror -Wconversion)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")
set(CXXFLAGS "-Wall -Werror -Wconversion")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

include_directories(include)
include_directories(src)

add_executable(listas
        main.cpp
        include/Lista.h
        include/Tarea.h
        src/Tarea.cpp
        include/Nodo.h

)

# Cambiar a main.exe para Windows.
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main.exe")