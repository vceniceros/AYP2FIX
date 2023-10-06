#include "Contacto.h"
#include <iostream>
using namespace std;

Contacto::Contacto(unsigned int numero, std::string nombre, std::string apellido) {
    this-> numero =numero;
    this-> nombre =nombre;
    this-> apellido =apellido;
}

void Contacto::mostrarInformacion() {
    cout<< numero << " - " << apellido << ", "<< nombre <<endl;
}

void Contacto::mostrarDireccion() {
    cout<< numero << "Direccion del numero: "<< &numero <<endl;
}