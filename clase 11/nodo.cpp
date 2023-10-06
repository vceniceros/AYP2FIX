#include "nodo.h"

Nodo::Nodo(Dato d, Nodo* ps) {
    dato = d;
    siguiente = ps;
}

Dato Nodo::obtener() {
    return dato;
}

Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}


void Nodo::cambiar_siguiente(Nodo* ps) {
    siguiente = ps;
}
