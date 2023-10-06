//
// Created by valen on 5/9/2023.
//
#include <string>
#include <vector>
#ifndef TP0_MODIFICARSTRINGS_H
#define TP0_MODIFICARSTRINGS_H
using namespace std;
class ManipularStrings{
public :
    static bool encontrarPalabraEnCadena(string & cadena, const string & palabra);
    //PRE: entran dos String
    //POST: retorna true si la segunda esta incluida en la primera

    static bool encontrarPalabraEnVector(string & cadena, const vector<string> & palabras);
    //PRE: entra un string y un vector de strings
    //POST: retorna true si un componente del vector estan en la cadena

    static string invertirCaracteres(string & palabra);
    //PRE:entra un string
    //POST:retorna el string dado vuelta

    static string convertirMinusculas(string &palabra);
    //PRE:entra un string
    //POST:retorna el string en minusculas

};


#endif //TP0_MODIFICARSTRINGS_H
