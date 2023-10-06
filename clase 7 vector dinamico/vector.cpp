//
// Created by ceni on 19/09/23.
//

#include "vector.h"

vector::vector(int l) {
    this->longitud = l;
    this->datos = new Dato[l];
}

void vector::insertar(Dato d, int pos) {
    datos[pos] = d;
}

Dato vector::obetener(int pos) {
    return datos[pos];
}
int vector::obtener_longitud() {
    return longitud;
}


vector::~vector() {
    delete [] datos;
}