#include "Vector.hpp"



Vector::Vector() {
    this->tamanioMaximo = TAMANIOMINIMO;
    this->cantidadDatos = 0;
    this->datos = new Item*[tamanioMaximo];

}

bool Vector::vacio() {
    return cantidadDatos==0;
}

size_t Vector::tamanio() {
    return cantidadDatos;
}

Item *&Vector::operator[](size_t indice) {
   if(indice < tamanio()){
       return datos[indice];
   }else{
       throw VectorException();
   }

}


void Vector::redimensionar(size_t nuevoTamanio){
    Item** datos_aux = datos;
    datos = new Item*[nuevoTamanio];
    for(size_t i = 0; i < cantidadDatos; i++){
        datos[i] = datos_aux[i];
    }
    this->tamanioMaximo = nuevoTamanio;
    delete[] datos_aux;
}

void Vector::alta(Item *dato) {
    if(cantidadDatos + 1 == tamanioMaximo){
        redimensionar(tamanioMaximo * 2);
    }
        datos[cantidadDatos] = dato;
        cantidadDatos++;

}

void Vector::alta(Item *dato, size_t indice) {
    Item *dato_aux;
    if(cantidadDatos + 1 >= tamanioMaximo){
        redimensionar(tamanioMaximo * 2);
    }
    if(indice < tamanio()){
        while(datos[indice+1] != nullptr){
            dato_aux = datos[indice];
            datos[indice + 1] = dato_aux;
        }
        datos[indice] = dato;
        cantidadDatos++;
    }else if(indice == tamanio()){
        alta(dato);
    }else{
        throw VectorException();
    }
}

Item *Vector::baja() {
    if(cantidadDatos < tamanioMaximo / 4 && tamanioMaximo>TAMANIOMINIMO){
        redimensionar(tamanioMaximo / 2);
    }
    if(!vacio()){
        Item** datos_aux = new Item*[tamanioMaximo];
        Item* dato_aux = datos[tamanio()-1];
        for(size_t i = 0; i < tamanio()-1; i++){
            datos_aux[i] = datos[i];
        }
        datos = datos_aux;
        cantidadDatos--;
        return dato_aux;
    }else{
        throw VectorException();
    }

}

Item *Vector::baja(size_t indice) {
    if(cantidadDatos < tamanioMaximo / 4 && tamanioMaximo>TAMANIOMINIMO){
        redimensionar(tamanioMaximo / 2);
    }
    if(!vacio() && indice < cantidadDatos){
        Item** datos_aux = new Item*[tamanioMaximo];
        Item* dato_aux = datos[indice];
        for(size_t i = 0, j = 0; i < cantidadDatos; i++){
           if(i != indice){
            datos_aux[j] = datos[i];
            ++j;
           }
        }
        datos = datos_aux;
        cantidadDatos--;
        return dato_aux;
    }else if(vacio()){
        throw VectorException();
    }else{
        throw VectorException();
    }
}
Vector::~Vector() {
    delete[] datos;
}