//
// Created by valen on 13/10/2023.
//
#include "cola_eventos.h"

cola_eventos::cola_eventos() {
    this->cola = new Cola<Evento>;
}

void cola_eventos::acolar(std::string & nombre_evento) {
        if(nombre_evento == ACCION_GUARDADO || nombre_evento == ACCION_APERTURA_MAPA){
            Evento nuevo_evento(nombre_evento);
            cola->alta(nuevo_evento);
        }else{
            std::cout<<"tipo de evento equivocado, favor ingresar un tipo valido"<<std::endl;
        }
}

bool cola_eventos::evaluar_desorientado(int aperturas_mapa, int guardados) {
    return (aperturas_mapa > guardados && aperturas_mapa > PERDIDO && guardados < GUARDADOS_DE_UN_COBARDE);
}

bool cola_eventos::evaluar_precavido(int aperturas_mapa, int guardados) {
    return (guardados > aperturas_mapa &&  guardados > GUARDADOS_RESPETABLES && guardados < GUARDADOS_DE_UN_COBARDE);
}

bool cola_eventos::evaluar_asustado(int guardados) {
    return guardados >= GUARDADOS_DE_UN_COBARDE;
}

std::string cola_eventos::descolar() {
    std::string perfil;
    bool perfil_desorientado = false;
    bool perfil_precavido = false;
    bool perfil_asustado = false;
    int contador_aperturas_mapa = 0;
    int contador_guardados = 0;
    while(!perfil_asustado && !cola->vacio()){
        Evento evento_aux = cola->ultimo();
        if (evento_aux == ACCION_APERTURA_MAPA){
            contador_aperturas_mapa++;
        }else if(evento_aux == ACCION_GUARDADO){
            contador_guardados++;
        }
        if(evaluar_desorientado(contador_aperturas_mapa, contador_guardados)){
            perfil_desorientado = true;
        }else if(evaluar_precavido(contador_aperturas_mapa, contador_guardados)){
            perfil_precavido = true;
        }else if(evaluar_asustado(contador_guardados)){
            perfil_asustado = true;
            perfil_precavido = false;
        }
        cola->baja();
    }
    if(perfil_precavido){
        perfil = PRECAVIDO;
    }else if(perfil_desorientado){
        perfil = DESORIENTADO;
    }else if(perfil_asustado){
        perfil = ASUSTADO;
    }else{
        perfil = INDETERMINADO;
    }
    return perfil;
}

void cola_eventos::mostrar() {
    std::string perfil = descolar();
    if(perfil == DESORIENTADO) {
        std::cout << "Aumento de factores ambientales" << std::endl;
    }else if(perfil == PRECAVIDO){
        std::cout << "Aumento en la cantidad de enemigos" << std::endl;
    }else if(perfil == ASUSTADO){
        std::cout << "Evento Pyramid Head adelantado" << std::endl;
    }else if(perfil == INDETERMINADO){
        std::cout << "Comportamiento aun no definido" << std::endl;
    }
}

cola_eventos::~cola_eventos() {
    while(!cola->vacio()){
        cola->baja();
    }
}







