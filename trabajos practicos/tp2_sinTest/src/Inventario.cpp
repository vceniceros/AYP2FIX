//
// Created by ceni on 23/09/23.
//
#include "Inventario.hpp"


Inventario::Inventario() {
    this->limiteDeItems = CANTIDAD_MAXIMA;
    this->inventario = new Lista_de<Item*>;
}


bool Inventario::limite_de_items_alcanzado() {
    return inventario->tamanio() >= limiteDeItems;
}

void Inventario::dividir_linea(const std::string& linea, std::string& nombre, std::string& tipo) {
    size_t posicion_coma = linea.find(',');
    if(posicion_coma != std::string::npos) {
        nombre = linea.substr(0, posicion_coma);
        tipo = linea.substr(posicion_coma + 1);
    }else{
        nombre = linea;
        tipo = "";
    }
}

Item *Inventario::generar_item(std::string nombre, std::string tipo) {
    return new Item(nombre,tipo);
}

void Inventario::Guardar_items() {
    std::ofstream archivo_guardar(RUTA);
    if (!archivo_guardar.is_open()) {
        std::cout << "El archivo no pudo abrirse." << std::endl;
    } else {
        for (size_t i = 0; i < inventario->tamanio(); i++) {
            Item* item = inventario->elemento(i);
            if (item) {
                archivo_guardar << *item;
                archivo_guardar << std::endl;
            }
        }
        archivo_guardar.close();
    }
}
void Inventario::Cargar_items() {
    std::ifstream archivo_guardado(RUTA);
    std::string linea;
    if(!archivo_guardado.is_open()){
        std::cout<<"archivo no existe"<<std::endl;
    }else{
        while(getline(archivo_guardado, linea)){
            std::string nombre, tipo;
            dividir_linea(linea, nombre, tipo);
            Item* item = generar_item(nombre, tipo);
            if(item){
                inventario->alta(item);
            }
        }
        archivo_guardado.close();
    }
}

void Inventario::alta(std::string &nombre, std::string &tipo) {
    if(!limite_de_items_alcanzado()){
        if(tipo == TIPO_CURATIVO || tipo == TIPO_MUNICION || tipo == TIPO_PUZZLE){
            Item* item = generar_item(nombre, tipo);
            inventario->alta(item);
        }else{
            std::cout<<"tipo invalido"<<std::endl;
        }
    }else{
        std::cout<<"a excedido el limite del inventario"<<std::endl;
    }
}

void Inventario::Baja(std::string dato) {
    if(!inventario->vacio()){
        size_t i = 0;
        bool seEncontro = false;
        while(i < inventario->tamanio() && !seEncontro){
            if(inventario->elemento(i)->operator==(dato)){
                inventario->baja(i);
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
    for(size_t i = 0; i < inventario->tamanio(); i++){
        size_t j = i+1;
        std::cout<<j;
        std::cout<<"-";
        inventario->elemento(i)->listar_informacion();
        std::cout<<std::endl;
    }
}
Inventario::~Inventario() {
    while (!inventario->vacio()){
        inventario->baja();
    }
}
