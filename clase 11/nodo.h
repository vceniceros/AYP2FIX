#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED



typedef int Dato;


class Nodo {
private:
    Dato dato;
    Nodo* siguiente;

public:
    //pre:
    //pos: construye el nodo con el dato d y el siguiente en 0
    Nodo(Dato d, Nodo* ps = 0);

    void cambiar_siguiente(Nodo* ps);

    Dato obtener();

    Nodo* obtener_siguiente();

};

#endif // NODO_H_INCLUDED
