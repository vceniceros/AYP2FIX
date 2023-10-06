//
// Created by ceni on 19/09/23.
//

#ifndef CLASE_7_VECTOR_DINAMICO_VECTOR_H
#define CLASE_7_VECTOR_DINAMICO_VECTOR_H

typedef int Dato;

class vector {
private:
    int longitud;
    Dato* datos;
public:
    //PRE: l > 0;
    //POST: crea un vector sin inicializar la longitud l
    vector(int l);

    //PRE: 0 <= pos< longitud
    //POST: modifica al vector poniendo el dato d en la poscision pos
    void insertar(Dato d, int pos);

    //PRE: 0 <= pos< longitud
    //POST: devuelve el dato que esta en la posicion pos
    Dato obetener(int pos);
    int obtener_longitud();

    ~vector();
};


#endif //CLASE_7_VECTOR_DINAMICO_VECTOR_H
