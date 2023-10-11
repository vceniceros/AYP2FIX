
#ifndef TAREA_H_INCLUDED
#define TAREA_H_INCLUDED

#include <string>

class Tarea {
private:
    std::string titulo;
    bool estado;

public:
    Tarea();
    Tarea(std::string & titulo);
    void cambiar_estado();
    std::string mostrar_titulo();
};

#endif // TAREA_H_INCLUDED