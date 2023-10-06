//
// Created by valen on 1/9/2023.
//
#include <string>
#include "ManipularStrings.h"
#ifndef AYP2_FANTASMA_H
#define AYP2_FANTASMA_H
using namespace std;
const string RESPUESTA_DEFAULT = "...";
const int PREGUNTAS_MAXIMAS = 5;
const vector<string> ABRIR = {"abrir", "abro", "abre"};
const string MIEDO = "miedo";
const string COMO_TE_LLAMAS = "como te llamas";
const string CUANTOS_ANIOS = "cuantos anios";
const string DONDE_ESTAS = "donde estas";
const string COMO_ESTAS = "como estas";


class Fantasma {
private:
    bool suspension;
    string respuestas;
    int contadorDePreguntas;
public:
     Fantasma() = default;//constructor default

     Fantasma(bool & suspension, string & respuestas, int & contadorDePreguntas);//constructor completo

     string responderPreguntas(string pregunta);
     //PRE: entra un string con la pregunta
     //POST: retorna un string con la respuesta

     static void bienvenida();//muestra el saludo

     static void despedida();//muestra la despedida

     void cambioDeEstado();
     //PRE: se llama suspension siendo false
     //POST: se le cambia el estado a verdader

     void incrementarContador();
     //PRE: se llama al contadorDePreguntas
     //POST: se le aumenta el valor en 1
};


#endif //AYP2_FANTASMA_H
