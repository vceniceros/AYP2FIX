//
// Created by ceni on 07/09/23.
//

#ifndef AYP2_CONTACTO_H
#define AYP2_CONTACTO_H


class Contacto {
private:
    char* nombre;
    long int numero;
public:
    Contacto(char* & nombre, long int & numero);
    void cambiarNombre(char* & nombre);
    void cambiarNumero(long int & numero);
};


#endif //AYP2_CONTACTO_H
