//
// Created by ceni on 28/09/23.
//

#ifndef CLASE_10_PILA_H
#define CLASE_10_PILA_H
typedef int Dato;
const int MAX = 10;
class Pila{
private:
    int ultimo;
    Dato elementos[MAX];
public:
    //constructor
    //PRE:
    //POST: crea una pila vacia
    Pila();
    //alta
    //PRE:la pila no puede estar vacia
    //POST: devuelve el dato y lo saca de pila
    void  alta(Dato d);
    //baja
    //PRE:la pila no puede estar vacia
    //POST: devuelve el dato y lo saca de pila
    Dato baja();
    //consulta
    //PRE:la pila no puede estar vacia
    //POST: devuelve el dato
    Dato consulta();
    //vacia
    //PRE:
    //POST: muestra si la pila esta vacia
    bool vacia();
    //llena
    //PRE:
    //POST: muestra si la pila esta llena
    bool llena();

};



#endif //CLASE_10_PILA_H
