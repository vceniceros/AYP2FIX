//
// Created by ceni on 26/09/23.
//
#include "Menu.hpp"

using namespace std;
void Menu::menu() {
    Inventario inventario;
    inventario.CargarItems();
    string entrada;
    cout<<"Ingrese SALIR para finalizar ejecucion"<<endl;
    while(entrada != "salir"){
        cout<<"Accion en el invetario: ";
        cin>>entrada;
        cout<<endl;
        if(entrada == "ALTA"){
            string nombre, tipo;
            cout<<"ingrese nombre del item: ";
            cin>>nombre;
            cout<<endl;
            cout<<"ingrese tipo del item: ";
            cin>>tipo;
            cout<<endl;
            Item* item = inventario.generar_item(nombre,tipo);
            inventario.alta(item);
        }else if(entrada == "BAJA"){
            string nombre;
            cout<<"ingrese nombre del item a eliminar: ";
            cin>>nombre;
            inventario.Baja(nombre);
            cout<<endl;
        } else if(entrada == "CONSULTA"){
            inventario.Consulta();
        }
        cout<<"Accion en el invetario: ";
    }
    inventario.GuardarItems();
}