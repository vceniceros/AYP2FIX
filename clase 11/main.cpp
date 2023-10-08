#include <iostream>
#include "lista.h"


using namespace std;

int main(){

    Lista l;
    l.alta(5, 1);
    l.alta(8, 1);
    l.alta(3, 2);
    l.alta(7, 4);

    l.reiniciar();
/*
    while (l.hay_siguiente())
        cout << l.siguiente() << endl;
*/
    /*
    for (int i = 1; i <= l.obtener_cantidad(); i++)
        cout << l.consulta(i) << endl;
        */

    /*
    l.baja(4);
    cout << "Despues de la baja" << endl;
    for (int i = 1; i <= l.obtener_cantidad(); i++)
        cout << l.consulta(i) << endl;
    */

  return 0;
}
