#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <exception>

class VectorException : public std::exception {
    // Excepcion especifica y exclusivamente para errores dentro del VectorTemplate.
    // Usar de la forma "throw VectorException();" cuando una precondicion no se cumpla.

    // Ejemplo:
    //     if (condicion_de_error()){
    //         throw VectorException();
    //     }
};
const size_t TAMANIOMINIMO = 10;
template <typename Dato>
class Vector{
    Dato* datos;
    size_t cantidadDatos;
    size_t tamanioMaximo;

    void redimensionar(size_t nuevoTamanio){
        Dato* datos_aux = datos;
        datos = new Dato[nuevoTamanio];
        for(size_t i = 0; i < cantidadDatos; i++){
            datos[i] = datos_aux[i];
        }
        this->tamanioMaximo = nuevoTamanio;
        delete[] datos_aux;
    }
public:
    // Constructor.
    Vector() {
        this->tamanioMaximo = TAMANIOMINIMO;
        this->cantidadDatos = 0;
        this->datos = new Dato[tamanioMaximo];

    }
    // Pre: -
    // Post: Devuelve true si el vector esta vacio (es decir, si no hay datos).
    bool vacio() {
        return cantidadDatos==0;
    }

    // Pre: -
    // Post: Devuelve la cantidad de datos del vector.
    size_t tamanio() {
        return cantidadDatos;
    }
    // Pre: El vector no puede estar vacio. El indice debe ser menor que la cantidad de datos.
    // Post: Devuelve una referencia al dato deseado.
    Dato &operator[](size_t indice) {
        if(!vacio()){
            if(indice < tamanio()){
                return datos[indice];
            }else{
                throw VectorException();
            }
        }else{
            throw VectorException();
        }
    }

    // Pre: -
    // Post: Agrega el dato al final del vector.
    void alta(Dato dato) {
        if(cantidadDatos + 1 == tamanioMaximo){
            redimensionar(tamanioMaximo * 2);
        }
        datos[cantidadDatos] = dato;
        cantidadDatos++;

    }

    void alta(Dato dato, size_t indice) {
        Dato dato_aux;
        if(cantidadDatos + 1 >= tamanioMaximo){
            redimensionar(tamanioMaximo * 2);
        }
        if(indice < tamanio()){
            for (size_t i = cantidadDatos; i > indice; i--) {
                datos[i] = datos[i - 1];
            }
            datos[indice] = dato;
            cantidadDatos++;
        }else if(indice == tamanio()){
            alta(dato);
        }else{
            throw VectorException();
        }
    }


    Dato baja() {
        if(cantidadDatos < tamanioMaximo / 4 && tamanioMaximo>TAMANIOMINIMO){
            redimensionar(tamanioMaximo / 2);
        }
        if(!vacio()){
            Dato* datos_aux = new Dato[tamanioMaximo];
            Dato dato_aux = datos[tamanio()-1];
            for(size_t i = 0; i < tamanio()-1; i++){
                datos_aux[i] = datos[i];
            }
            delete[] datos;
            datos = datos_aux;
            cantidadDatos--;
            return dato_aux;
        }else{
            throw VectorException();
        }

    }

    // Pre: El vector no puede estar vacio. El indice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posicion indicada, moviendo todos los elementos siguientes. Si el indice es igual a
    // la cantidad de datos - 1, simplemente elimina el ultimo dato.
    Dato baja(size_t indice) {
        if(cantidadDatos < tamanioMaximo / 4 && tamanioMaximo>TAMANIOMINIMO){
            redimensionar(tamanioMaximo / 2);
        }
        if(!vacio() && indice < cantidadDatos){
            Dato* datos_aux = new Dato[tamanioMaximo];
            Dato dato_aux = datos[indice];
            for(size_t i = 0, j = 0; i < cantidadDatos; i++){
                if(i != indice){
                    datos_aux[j] = datos[i];
                    ++j;
                }
            }
            delete[]  datos;
            datos = datos_aux;
            cantidadDatos--;
            return dato_aux;
        }else if(vacio()){
            throw VectorException();
        }else{
            throw VectorException();
        }
    }

    // Destructor.
    ~Vector() {
        delete[] this->datos;
    }
};

#endif