#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"


class Lista {
private:
    Nodo* primero;
    Nodo* cursor;
    int cantidad;


public:
    //constructor
    //pre:
    //pos: crea una Lista vacia
    Lista();

    //pre:
    //pos: libera la memoria utilizada
    ~Lista();

    //alta
    //pre: pos mayor a 0 y menor o igual que obtener_cantidad + 1, la primera posicion es la 1
    //pos: agrega d en la posicion pos
    void alta(Dato d, int pos);

    //baja
    //pre: pos mayor a 0 y menor o igual que obtener_cantidad
    //pos: saca el dato que esta en la posicion pos de la lista
    void baja(int pos);

    //consulta
    //pre: pos mayor a 0 y menor o igual que obtener_cantidad
    //pos: devuelve el dato que esta en la posicion pos de la lista
    Dato consulta(int pos);

    //pre:
    //pos: devuelve true si la Lista esta vacia, si no, false
    bool vacia();


    //pre:
    //pos: devuelve la cantidad de elementos de la lista
    int obtener_cantidad();

    /*
    pre: -
    pos: true si hay algun dato mas
         false si no
         */
    bool hay_siguiente();

    //pre: hay_siguiente tiene que haber devuelto true
    //pos: devuelve el dato y avanza el cursor
    Dato siguiente();

    //pre: -
    //pos: pone el cursor al principio de la lista
    void reiniciar();

private:
    //pre: pos mayor a 0 y menor o igual que obtener_cantidad
    //pos: devuelve un puntero al Nodo que esta en la posicion pos
    Nodo* obtener(int pos);
};

#endif // LISTA_H_INCLUDED
