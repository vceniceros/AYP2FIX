//
// Created by valen on 13/10/2023.
//
#include "Menu.h"
using namespace std;
cola_eventos cola;
void Menu::menu_cola_eventos() {
    string opcion;
    while (opcion != "salir"){
        cout<<"ingrese salir para terminar con la carga de elementos"<<endl;
        cout<<"si desea cargar un evento pulse s"<<endl;
        cin>>opcion;
        if(opcion == "s"){
            cout<<"ingrese 1 para guadado, 2 para abrir mapa"<<endl;
            int evento = 0;
            cin>>evento;
            string guardado = ACCION_GUARDADO;
            string mapa = ACCION_APERTURA_MAPA;
            switch (evento) {
                case 1:
                    cola.acolar(guardado);
                    break;
                case 2:
                    cola.acolar(mapa);
                    break;
                default:
                    cout<<"ingreso erroneo"<<endl;
                    break;
            }
        }
    }
    cola.mostrar();
}
