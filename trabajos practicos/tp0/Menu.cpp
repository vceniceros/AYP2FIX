//
// Created by valen on 6/9/2023.
//

#include "Menu.h"
#include <iostream>
#include "fantasma.h"


Fantasma fantasma;

 void Menu::solicitarPreguntas(){
     cout<< "ingrese salir para salir" << endl;
    string preguntas;
    Fantasma::bienvenida();
    cout << "mensaje captado por el fantasma: ";
    while (preguntas != "salir") {
        getline(cin, preguntas);
        cout << fantasma.responderPreguntas(preguntas) << endl;
        cout << "mensaje captado por el fantasma: ";
    }
    Fantasma::despedida();

}