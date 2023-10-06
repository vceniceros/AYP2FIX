//
// Created by ceni on 26/09/23.
//
#include "Menu.hpp"

using namespace std;

void Menu::alta(Inventario &inventario) {
    string nombre, tipo;
    int opcion;
    cout<<"ingrese nombre del item: ";
    cin>>nombre;
    cout<<endl;
    cout<<"ingrese tipo del item: "<< endl;
    cout << "1. CURATIVO" << endl;
    cout << "2. MUNICION" << endl;
    cout << "3. PUZZLE" << endl;
    cin>>opcion;
    if(opcion == 1){
        tipo = TIPO_CURATIVO;
    }else if (opcion == 2){
        tipo = TIPO_MUNICION;
    }else if(opcion == 3){
        tipo = TIPO_PUZZLE;
    }else{
        cout<<"opcion invalida"<<endl;
    }
    inventario.alta(nombre, tipo);
    cout<<endl;
}

void Menu::baja(Inventario &inventario) {
    string nombre;
    cout<<"ingrese nombre del item a eliminar: ";
    cin>>nombre;
    inventario.Baja(nombre);
    cout<<endl;
}

void Menu::consulta(Inventario &inventario) {
    inventario.Consulta();
}
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
           Menu::alta(inventario);
        }else if(entrada == "BAJA"){
            Menu::baja(inventario);
        } else if(entrada == "CONSULTA") {
            Menu::consulta(inventario);
        }else if(entrada == "salir" || entrada == "SALIR"){
                entrada = "salir";
        }else{
            cout<<"ingreso invalido, favor de ingresar un valor valido (ALTA, BAJA, CONSULTA)"<<endl;
            cin>>entrada;
        }
    }
    inventario.GuardarItems();
}