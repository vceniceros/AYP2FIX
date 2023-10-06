//
// Created by valen on 1/9/2023.
//

#include <cctype>
#include "ManipularStrings.h"
using namespace std;


bool ManipularStrings::encontrarPalabraEnCadena(string & cadena, const string & palabra){
    size_t buscar = cadena.find(palabra);
    return (buscar != string::npos);//npos es la constante que se utiliza para señalar la no existencia del indice dentro de la cadena
}
bool ManipularStrings::encontrarPalabraEnVector(string & cadena, const vector<string> & palabras) {
    size_t i = 0;
    bool resultado = false;
    while(i <= palabras.size() && !resultado){
        size_t indice = cadena.find(palabras[i]);
        if(indice != string::npos){
            resultado = true;
        }
        i++;
    }
    return resultado;
}

string ManipularStrings::invertirCaracteres(string & palabra){
    string palabraInvertida;
    string palabraAux;
    for(size_t i = (palabra.length()-1); i > 0; i--){
        if(palabra[i] != ' '){
            palabraAux += palabra[i];
        }else{
            palabraInvertida += palabraAux + ' ';
            palabraAux = "";
        }
    }
    palabraInvertida += palabraAux;
        return  palabraInvertida;
}
string ManipularStrings::convertirMinusculas(string &palabra){
    string palabraLower;
    for(long unsigned int i = 0;i < palabra.length(); i++){
        palabraLower += char(tolower(palabra[i]));
    }
    return palabraLower;
}



