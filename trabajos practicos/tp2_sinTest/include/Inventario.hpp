//
// Created by ceni on 23/09/23.
//
#include "Item.hpp"
#include "lista_de.hpp"
#include <fstream>
#include <string>
#include <iostream>


#ifndef VECTOR_TESTS_INVENTARIO_HPP
#define VECTOR_TESTS_INVENTARIO_HPP

const std::string RUTA = "save_file.csv";
const int CANTIDAD_MAXIMA = 15;
class Inventario{
private:
    size_t limiteDeItems;
    Lista_de<Item*>* inventario;
public:
    Inventario();

    //PRE:
    //POST: se guarda un item en el inventario
    void alta(std::string &nombre, std::string &tipo);

    //PRE:El inventario no debe estar vacio
    //POST: Elimina un item del inventario
    void Baja(std::string dato);

    //PRE:
    //POST:Muesta los items del inventario
    void Consulta();

    //PRE:
    //POST:Impide agregar items si el inventario esta lleno
    bool limite_de_items_alcanzado();

    //PRE:recibe una linea del csv
    //POST:dividi la linea en 2 elementos
    void dividir_linea(const std::string& linea, std::string& nombre, std::string& tipo);

    //PRE:
    //POST: genera un item por nombre y tipo
    Item* generar_item(std::string nombre, std::string tipo);

    //PRE:debe existir un csv: archivo.csv con items cargado en su defecto vacio
    //POST: Carga los items del csv al vector
    void Cargar_items();


    //PRE:debe existir un csv: archivo.csv con items cargado en su defecto vacio
    //POST: guarda los items del vector en el csv
    void Guardar_items();

    //destructor
    ~Inventario();

};
#endif
