#ifndef ALGO2_DOBLE_PUNTEROS_AGENDA_H
#define ALGO2_DOBLE_PUNTEROS_AGENDA_H

#include "Contacto.h"

class Agenda {
private:
    Contacto** contactos;
    size_t cantActual;
    size_t cantContactos;
public:
    Agenda(size_t cantContactos);
    Agenda(size_t cantContactos, std::string ruta);
    void agregarContacto(Contacto* contacto);
    void mostrarInformacion();
    void mostrarDirecciones();
    void guardarContactos(std::string RUTA_ARCHIVO);
    ~Agenda();
};

#endif