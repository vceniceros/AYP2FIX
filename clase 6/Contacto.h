#ifndef ALGO2_DOBLE_PUNTEROS_CONTACTO_H
#define ALGO2_DOBLE_PUNTEROS_CONTACTO_H

#include <string>

class Contacto {
private:
    unsigned int numero;
    std::string nombre;
    std::string apellido;
public:
    Contacto(unsigned int numero, std::string nombre, std::string apellido);
    void mostrarInformacion();
    void mostrarDireccion();
};

#endif