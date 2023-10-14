//
// Created by valen on 13/10/2023.
//

#ifndef TP2_MENU_COLA_H
#define TP2_MENU_COLA_H
#include "cola.hpp"
#include "evento.hpp"
#include <string>
#include <iostream>

//constantes
const std::string DESORIENTADO = "desorientado";
const std::string PRECAVIDO = "precavido";
const std::string ASUSTADO = "asustado";
const std::string INDETERMINADO = "no determinado";
const int GUARDADOS_DE_UN_COBARDE = 8;
const int GUARDADOS_RESPETABLES = 5;
const int PERDIDO = 5;

class cola_eventos{
private:
    Cola<Evento>* cola;
public:
    //constructor
    cola_eventos();

    //PRE:
    //POST: acola los eventos;
    void acolar(std::string & nombre_evento);

    //PRE:la cola tiene eventos
    //POST:descola los evento y retorna un perfil de jugador
     std::string descolar();

     //PRE:
     //POST: evalua si el jugador esta desorientado
     bool evaluar_desorientado(int aperturas_mapa, int guardados);

    //PRE:
    //POST: evalua si el jugador es precavido
    bool evaluar_precavido(int aperturas_mapa, int guardados);

    //PRE:
    //POST: evalua si el jugador esta asustado
    bool evaluar_asustado(int guardados);

    //PRE:se descolo
    //POST: muestra el evento a ejecutar segun el perfil de jugador
    void mostrar();
    //destructor
    ~cola_eventos();
};
#endif //TP2_MENU_COLA_H
