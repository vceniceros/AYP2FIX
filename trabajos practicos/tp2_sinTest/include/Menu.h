//
// Created by valen on 13/10/2023.
//

#ifndef TP2_MENU_H
#define TP2_MENU_H
#include "cola_eventos.h"
#include "Inventario.hpp"
class Menu{
public:
    //PRE:
    //POST: ejecuta el menu de cola
    static  void menu_cola_eventos();

    //PRE:
    //POST:da de alta un item
    static void menu_alta_invetario(Inventario &inventario);

    //PRE:inventario no puede esta vacio
    //POST:da de baja un item
    static void menu_baja_inventario(Inventario &inventario);

    //PRE:
    //POST: muestra todo el contenido del inventario
    static void menu_consulta(Inventario &inventario);

    //PRE:
    //POST:Muestra el menu de opciones
    static void menu_inventario();

    //PRE:
    //POST:muestra el menu principal
    static void menu_principal();

};
#endif //TP2_MENU_H
