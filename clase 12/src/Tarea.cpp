//
// Created by valen on 10/10/2023.
//

#include "Tarea.h"
Tarea::Tarea() {
    titulo = "";
    estado = false;
}
Tarea::Tarea(std::string & titulo) {
    this->titulo = titulo;
    this->estado = false;
}

void Tarea::cambiar_estado() {
    this->estado = true;
}

std::string Tarea::mostrar_titulo() {
    return titulo;
}



