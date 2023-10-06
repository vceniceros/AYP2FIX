#include <iostream>
#include "include/pila.h"
using namespace std;
int main() {
    Pila pila;

    pila.alta(4);
    pila.alta(5);
    pila.alta(10);
    pila.alta(11);
    pila.alta(23);
    pila.alta(10);
    pila.alta(0);
    pila.alta(40);
    pila.alta(17);
    while (!pila.vacia()){
        cout<<"el ulimo elemento es: "<<pila.baja()<<endl;
    }
}
