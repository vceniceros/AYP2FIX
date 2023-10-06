#include "lista.h"

//constructor
Lista::Lista() {
    primero = 0;
    cursor = 0;
    cantidad = 0;
}

//alta
void Lista::alta(Dato d, int pos) {
    Nodo* nuevo = new Nodo(d);
    if (pos == 1) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    }
    else {
        Nodo* anterior = obtener(pos - 1);
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

// consulta
Dato Lista::consulta(int pos) {
    Nodo* aux = obtener(pos);
    return aux->obtener();
}

// baja
void Lista::baja(int pos) {
    Nodo* baja = primero;
    if (pos == 1) {
        primero = baja->obtener_siguiente();
    }
    else {
        Nodo* anterior = obtener(pos - 1);
        baja = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(baja->obtener_siguiente());
    }
    delete baja;
    cantidad--;
}

bool Lista::vacia() {
    return (cantidad == 0);
}

Lista::~Lista() {
    while (! vacia())
        baja(1);
}


int Lista::obtener_cantidad() {
    return cantidad;
}

Nodo* Lista::obtener(int pos) {
    Nodo* aux = primero;
    for (int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}

void Lista::reiniciar() {
    cursor = primero;
}

bool Lista::hay_siguiente() {
    return (cursor != 0);
}

Dato Lista::siguiente() {
    Dato d = cursor->obtener();
    cursor = cursor->obtener_siguiente();
    return d;
}
