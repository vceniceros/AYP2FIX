//
// Created by ceni on 23/09/23.
//
#include "Inventario.hpp"


Inventario::Inventario(size_t limiteDeItems, Vector inventario) {
    this->limiteDeItems = 15;
    inventario = inventario;
}

bool Inventario::LimiteDeItemsAlcanzado() {
    return inventario.tamanio() == limiteDeItems;
}

void Inventario::dividirLinea(std::string linea, std::string primera, std::string segunda) {
    size_t posicionComa = linea.find(',');
    if(posicionComa != std::string::npos) {
        primera = linea.substr(0, posicionComa);
        segunda = linea.substr(posicionComa +1);
    }else {
        primera = linea;
        segunda = "";
    }
}

Item *Inventario::generar_item(std::string nombre, std::string tipo) {
    return new Item(nombre,tipo);
}

void Inventario::GuardarItems() {
    std::ofstream archivoAGuardar(RUTA);
    std::string linea;
    if (!archivoAGuardar.is_open()){
        std::cout<<"archivo no existe"<<std::endl;
    }else{
        size_t i = 0;
        while(i < inventario.tamanio()){
            archivoAGuardar << inventario[i] << std::endl;
        }
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
            Item* item = generar_item(nombre,tipo);
            inventario.alta(item);
        }
    }
}

void Inventario::alta(Item *dato) {
    if(!limiteDeItems){
        inventario.alta(dato);
    }else{
        std::cout<<"a excedido el limite del inventario"<<std::endl;
    }
}

void Inventario::Baja(std::string dato) {
    if(!inventario.vacio()){
        size_t i = 0;
        bool seEncontro = false;
        while(i <= inventario.tamanio() && !seEncontro){
            if(inventario[i]->operator==(dato)){
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
        std::cout<<i<<inventario[i]<<std::endl;
    }
}