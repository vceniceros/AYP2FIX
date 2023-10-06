//
// Created by ceni on 26/09/23.
//

#ifndef VECTOR_TESTS_MENU_HPP
#define VECTOR_TESTS_MENU_HPP
#include <string>
#include <iostream>
#include "Inventario.hpp"

class Menu{
private:

public:
    //PRE:
    //POST:Muestra el menu de opciones
    static void menu();

    //PRE:recibe un string nombre y un tipo de manera numerica
    //POST:da de alta un item
    static void alta(Inventario &inventario);

    //PRE:el item debe existir, inventario no debe esta vacio
    //POST:da de baja un item
    static void baja(Inventario &inventario);

    //PRE:
    //POST: muestra todo el contenido del inventario
    static void consulta(Inventario &inventario);
};
#endif //VECTOR_TESTS_MENU_HPP
