#include <iostream>
#include "Tarea.h"
#include "Lista.h"
using namespace std;
int main() {
    std::cout << "Agregue una tarea: " << std::endl;
    string  titulo1 = "empezar";
    Tarea tarea1 = Tarea(titulo1);
    Lista<Tarea> lista1;

    lista1.alta(tarea1, 1);


    std::cout << "Tarea en posicion 1: " << lista1.consulta(1).mostrar_titulo() << std::endl;


    return 0;
}
