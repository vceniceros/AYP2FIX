# El Inventario de James

Trabajo Práctico 1 de Algoritmos y Programación 2 2c2023.
Se recomienda fuertemente descargar esta plantilla u, opcionalmente, forkear el repositorio para versionarlo.

## Compilación:

El programa se puede compilar utilizando el **CMakeLists.txt** que está en el repositorio o bien ejecutando por consola:

> g++ -I include src/*.cpp -o programa -Wall -Werror -Wconversion

Al compilar con **CMake**, se deben agregar todos los archivos **.cpp** en la línea:

> add_executables(ayp2_plantilla_tp1_2c2023 main.cpp //Otros archivos//)

## Tests:

Para ejecutar los tests, basta con cargar el **CMakeLists.txt** que se encuentra dentro de la carpeta tests/.

## Organización de archivos:

En la carpeta src/ van a encontrar los archivos .cpp del proyecto.
En la carpeta include/ van a encontrar los headers del proyecto.
Es decisión del estudiante el cómo y donde se guardan los archivos **savefile.csv**, con la consideración de que se deben abrir usando rutas relativas.
