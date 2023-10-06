#include "Agenda.h"
#include "Lector.h"
#include <iostream>
using namespace std;

Agenda::Agenda(size_t cantContactos) {
    this->contactos = new Contacto* [cantContactos];
    this->cantContactos = cantContactos;
    this->cantActual = 0;
}
Agenda::Agenda(size_t cantContactos, std::string ruta) : Agenda(cantContactos) {
    Lector::procesarArchivo(this, ruta);
}

void Agenda::agregarContacto(Contacto *contacto) {
    if(cantActual < cantContactos){
        contactos[cantActual] = contacto;
        cantActual++;
    } else{
        delete contacto;
    }
}

void Agenda::mostrarInformacion() {
    for(size_t i = 0; i < cantActual; i++){
        contactos[i]->mostrarInformacion();
    }
    cout << endl;
}


void Agenda::mostrarDirecciones() {
    for(size_t i = 0; i < cantActual; i++){
        //& da la direccion de memoria de esa variable
        //tenemos punteros a contactos
        cout<<"Direccion del puntero: "<< &contactos[i] <<endl;
        cout<<"Direccion del contacto: "<< contactos[i] <<endl;
        contactos[i]->mostrarDireccion();
    }
}

void Agenda::guardarContactos(std::string RUTA_ARCHIVO) {

}


Agenda::~Agenda(){
    for(size_t i = 0; i < cantActual; i++){
        delete contactos[i];
    }
    delete[] contactos;
}
