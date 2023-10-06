//
// Created by ceni on 28/09/23.
//
#include "../include/pila.h"

Pila::Pila() {
    ultimo = 0;
}

void Pila::redimencionar() {

}

bool Pila::vacia() {
    return (ultimo == 0);
}
bool Pila::llena(){
    return (ultimo==MAX);
}

void Pila::alta(Dato d) {
    elementos[ultimo]= d;
    ultimo++;
}

Dato Pila::baja() {
    ultimo--;
    return elementos[ultimo];
}

Dato Pila::consulta() {
    return elementos[ultimo - 1];
}