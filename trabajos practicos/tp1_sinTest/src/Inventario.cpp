//
// Created by ceni on 23/09/23.
//
#include "Inventario.hpp"


Inventario::Inventario(size_t limiteDeItems, Vector<Item*> inventario) {
    this->limiteDeItems = limiteDeItems;
    this->inventario = inventario;
}

bool Inventario::limiteDeItemsAlcanzado() {
    limiteDeItems = 15;
    return inventario.tamanio() >= limiteDeItems;
}

void Inventario::dividirLinea(const std::string& linea, std::string& nombre, std::string& tipo) {
    size_t posicionComa = linea.find(',');
    if(posicionComa != std::string::npos) {
        nombre = linea.substr(0, posicionComa);
        tipo = linea.substr(posicionComa +1);
    }else{
        nombre = linea;
        tipo = "";
    }
}

Item *Inventario::generar_item(std::string nombre, std::string tipo) {
    return new Item(nombre,tipo);
}

void Inventario::GuardarItems() {
    std::ofstream archivoAGuardar(RUTA);
    if (!archivoAGuardar.is_open()) {
        std::cout << "El archivo no pudo abrirse." << std::endl;
    } else {
        for (size_t i = 0; i < inventario.tamanio(); i++) {
            Item* item = inventario[i];
            if (item) {
                archivoAGuardar << *item;
                archivoAGuardar << std::endl;
            }
        }
        archivoAGuardar.close();
    }
}
void Inventario::CargarItems() {
    std::ifstream archivoGuardado(RUTA);
    std::string linea;
    if(!archivoGuardado.is_open()){
        std::cout<<"archivo no existe"<<std::endl;
    }else{
        while(getline(archivoGuardado,linea)){
            std::string nombre, tipo;
            dividirLinea(linea, nombre, tipo);
            Item* item = generar_item(nombre, tipo);
            if(item){
                inventario.alta(item);
            }
        }
        archivoGuardado.close();
    }
}

void Inventario::alta(std::string &nombre, std::string &tipo) {
    if(!limiteDeItemsAlcanzado()){
        if(tipo == TIPO_CURATIVO || tipo == TIPO_MUNICION || tipo == TIPO_PUZZLE){
            Item* item = generar_item(nombre, tipo);
            inventario.alta(item);
        }else{
            std::cout<<"tipo invalido"<<std::endl;
        }
    }else{
        std::cout<<"a excedido el limite del inventario"<<std::endl;
    }
}

void Inventario::Baja(std::string dato) {
    if(!inventario.vacio()){
        size_t i = 0;
        bool seEncontro = false;
        while(i < inventario.tamanio() && !seEncontro){
            if(inventario[i]->operator==(dato)){
                delete inventario[i];
                inventario.baja(i);
                seEncontro = true;
            }
            i++;
        }
        if(!seEncontro){
            std::cout<<"el item no se encuentra en el inventario"<<std::endl;
        }
    }else{
        std::cout<<"el inventario esta vacio"<<std::endl;
    }
}

void Inventario::Consulta() {
    for(size_t i = 0; i < inventario.tamanio(); i++){
        size_t j = i+1;
        std::cout<<j;
        std::cout<<"-";
        inventario[i]->listarInformacion();
        std::cout<<std::endl;
    }
}
Inventario::~Inventario() {
    for (size_t i = 0; i < inventario.tamanio(); i++) {
        delete inventario[i];
    }
}