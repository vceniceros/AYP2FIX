//
// Created by valen on 13/10/2023.
//
#include "Menu.h"
using namespace std;

void Menu::menu_cola_eventos() {
    cola_eventos cola;
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
void Menu::menu_alta_invetario(Inventario &inventario) {
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

void Menu::menu_baja_inventario(Inventario &inventario) {
    string nombre;
    cout<<"ingrese nombre del item a eliminar: ";
    cin>>nombre;
    inventario.Baja(nombre);
    cout<<endl;
}

void Menu::menu_consulta(Inventario &inventario) {
    inventario.Consulta();
}


void Menu::menu_inventario() {
    Inventario inventario;
    inventario.Cargar_items();
    string entrada;
    cout<<"Ingrese SALIR para finalizar ejecucion"<<endl;
    while(entrada != "salir"){
        cout<<"Accion en el invetario: ";
        cin>>entrada;
        cout<<endl;
        if(entrada == "ALTA"){
            Menu::menu_alta_invetario(inventario);
        }else if(entrada == "BAJA"){
            Menu::menu_baja_inventario(inventario);
        } else if(entrada == "CONSULTA") {
            Menu::menu_consulta(inventario);
        }else if(entrada == "salir" || entrada == "SALIR"){
            entrada = "salir";
        }else{
            cout<<"ingreso invalido, favor de ingresar un valor valido (ALTA, BAJA, CONSULTA)"<<endl;
            cin>>entrada;
        }
    }
    inventario.Guardar_items();
}

void Menu::menu_principal() {
    cout<<"bienvenido al menu general de testeo del programa"<<endl;
    cout<<"pulse EVENTO para testear la cola de eventos, ITEM para los items, salir para finalizar"<<endl;
    string opcion;
    while(opcion != "salir"){
        cin>>opcion;
        if(opcion == "EVENTO"){
            menu_cola_eventos();
            cout<<"pulse EVENTO para testear la cola de eventos, ITEM para los items, salir para finalizar"<<endl;
        }else if(opcion == "ITEM"){
            menu_inventario();
            cout<<"pulse EVENTO para testear la cola de eventos, ITEM para los items, salir para finalizar"<<endl;
        }else{
            cout<<"opcion invalida, por favor elija una opcion correcta"<<endl;
        }
    };
}

