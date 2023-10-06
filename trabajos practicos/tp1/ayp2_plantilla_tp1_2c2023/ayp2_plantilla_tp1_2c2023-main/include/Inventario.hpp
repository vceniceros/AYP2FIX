//
// Created by ceni on 23/09/23.
//
#include "Item.hpp"
#include "Vector.hpp"
#include <fstream>
#include <string>
#include <iostream>


#ifndef VECTOR_TESTS_INVENTARIO_HPP
#define VECTOR_TESTS_INVENTARIO_HPP

const std::string RUTA = "../saveFile.csv";

class Inventario{
private:
    size_t limiteDeItems;
    Vector inventario;
public:
    Inventario(size_t limiteDeItems, Vector invetario);

    Inventario() = default;

    //PRE:
    //POST: se guarda un item en el inventario
    void alta(Item* dato);

    //PRE:El inventario no debe estar vacio
    //POST: Elimina un item del inventario
    void Baja(std::string dato);

    //PRE:
    //POST:Muesta los items del inventario
    void Consulta();

    //PRE:
    //POST:Impide agregar items si el inventario esta lleno
    bool LimiteDeItemsAlcanzado();

    //PRE:recibe una linea del csv
    //POST:dividi la linea en 2 elementos
    void dividirLinea(std::string linea, std::string primera, std::string segunda);

    //PRE:
    //POST: genera un item por nombre y tipo
    Item* generar_item(std::string nombre, std::string tipo);

    //PRE:debe existir un csv: archivo.csv con items cargado en su defecto vacio
    //POST: Carga los items del csv al vector
    void CargarItems();


    //PRE:debe existir un csv: archivo.csv con items cargado en su defecto vacio
    //POST: guarda los items del vector en el csv
    void GuardarItems();
};
#endif
