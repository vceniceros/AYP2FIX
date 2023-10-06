//
// Created by valen on 1/9/2023.
//

#include "fantasma.h"
#include <iostream>



using namespace std;

Fantasma::Fantasma(bool & suspension, string & respuestas, int & contadorDePreguntas) {
    this -> respuestas = respuestas;
    this -> suspension = suspension = false;
    this -> contadorDePreguntas = contadorDePreguntas = 0;
}

void Fantasma::bienvenida() {
    cout<<"quien osa perturbar mi letargo"<<endl;
}

void  Fantasma::cambioDeEstado() {
    suspension = true;
}

void Fantasma::incrementarContador() {
    contadorDePreguntas++;
}

string Fantasma::responderPreguntas(std::string pregunta) {
    
    ManipularStrings::convertirMinusculas(pregunta);

    if (!suspension && ManipularStrings::encontrarPalabraEnCadena(pregunta, COMO_TE_LLAMAS)) {
        respuestas = "Mi nombre...No recuerdo mi nombre...";
        Fantasma::incrementarContador();

    } else if (!suspension && ManipularStrings::encontrarPalabraEnCadena(pregunta, CUANTOS_ANIOS)) {
        respuestas = "Llevo 109 anios acá...Creo que mori hace bastante...";
        Fantasma::incrementarContador();

    } else if (!suspension && ManipularStrings::encontrarPalabraEnCadena(pregunta, DONDE_ESTAS)) {
        respuestas = "Me encuentro en un limbo entre la vida y la muerte...";
        Fantasma::incrementarContador();

    } else if (!suspension && ManipularStrings::encontrarPalabraEnCadena(pregunta, COMO_ESTAS)) {
        respuestas = "/silencio/";
        Fantasma::incrementarContador();

    } else if (!suspension && ManipularStrings::encontrarPalabraEnVector(pregunta, ABRIR)) {
        respuestas = "/agitar_puerta/";
        Fantasma::incrementarContador();

    } else if (!suspension && ManipularStrings::encontrarPalabraEnCadena(pregunta, MIEDO)) {
        respuestas = "/abrir_puerta/ /risa_demoniaca/";
        Fantasma::cambioDeEstado();

    } else if (!suspension && pregunta.length() > 50) {
        respuestas = RESPUESTA_DEFAULT;
        Fantasma::incrementarContador();

    } else if(!suspension && contadorDePreguntas >= PREGUNTAS_MAXIMAS){
        Fantasma::cambioDeEstado();

    } else if(suspension){
        respuestas = RESPUESTA_DEFAULT;

    }else{
            respuestas = ManipularStrings::invertirCaracteres(pregunta);
            Fantasma::incrementarContador();
    }

    return respuestas;
    }



void Fantasma::despedida() {
    cout<<"te perseguire por el resto de tus dias!!"<<endl;
}
