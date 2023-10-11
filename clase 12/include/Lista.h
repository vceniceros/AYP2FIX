//
// Created by valen on 10/10/2023.
//

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <cstddef>
#include "nodo.h"

template<typename T>
class Lista {
private:
    Nodo<T> *primero;
    Nodo<T> *cursor;
    size_t cantidad;
    //pre: pos mayor a 0 y menor o igual que obtener_cantidad
    //pos: devuelve un puntero al Nodo que esta en la posicion pos
    Nodo<T>* obtener(size_t pos){
        Nodo<T>* aux = primero;
        for (size_t i = 1; i < pos; i++)
            aux = aux->obtener_siguiente();
        return aux;
    };

public:
    //constructor
    //pre:
    //pos: crea una Lista vacia
    Lista(){
        this->primero=0;
        this->cursor=0;
        this->cantidad = 0;
    };


    //alta
    //pre: pos mayor a 0 y menor o igual que obtener_cantidad + 1, la primera posicion es la 1
    //pos: agrega d en la posicion pos
    void alta(T d, size_t pos){
        Nodo<T>* nuevo = new Nodo(d);
        if (pos == 1) {
            nuevo->cambiar_siguiente(primero);
            primero = nuevo;
        }
        else {
            Nodo<T>* anterior = obtener(pos - 1);
            nuevo->cambiar_siguiente(anterior->obtener_siguiente());
            anterior->cambiar_siguiente(nuevo);
        }
        cantidad++;
    };

    //baja
    //pre: pos mayor a 0 y menor o igual que obtener_cantidad
    //pos: saca el dato que esta en la posicion pos de la lista
    void baja(size_t pos){
        Nodo<T>* baja = primero;
        if (pos == 1) {
            primero = baja->obtener_siguiente();
        }
        else {
            Nodo<T>* anterior = obtener(pos - 1);
            baja = anterior->obtener_siguiente();
            anterior->cambiar_siguiente(baja->obtener_siguiente());
        }
        delete baja;
        cantidad--;
    };

    //consulta
    //pre: pos mayor a 0 y menor o igual que obtener_cantidad
    //pos: devuelve el dato que esta en la posicion pos de la lista
    T consulta(size_t pos){
        Nodo<T>* aux = primero;
        for (size_t i = 1; i < pos; i++)
            aux = aux->obtener_siguiente();
        return aux->obtener_dato();
    };

    //pre:
    //pos: devuelve true si la Lista esta vacia, si no, false
    bool vacia(){
        return (cantidad ==0);
    };


    //pre:
    //pos: devuelve la cantidad de elementos de la lista
    size_t obtener_cantidad(){
        return cantidad;
    };

    /*
    pre: -
    pos: true si hay algun dato mas
         false si no
         */
    bool hay_siguiente(){
        return (cursor != 0);
    };

    //pre: hay_siguiente tiene que haber devuelto true
    //pos: devuelve el dato y avanza el cursor
    T siguiente(){
        T d = cursor->obtener();
        cursor = cursor->obtener_siguiente();
        return d;
    };

    //pre: -
    //pos: pone el cursor al principio de la lista
    void reiniciar(){
        cursor = primero;
    };

    //pre:
    //pos: libera la memoria utilizada
    ~Lista(){
        while (! vacia())
            baja(1);
    };

};

#endif // LISTA_H_INCLUDED