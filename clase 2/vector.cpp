//
// Created by ceni on 29/08/23.
//
#include <iostream>
#include <vector>

using namespace std;

void imprimirNumeros(vector<int>& numeros){// sin el & me hace una copia, no modifica al mismo vector
    for(int  i = 0; i < size(numeros); i++){//size es largo del vector, size of es largo en bits
        cout<<numeros[i]<<endl;
    }
}

int main(){
    vector<int> numeros = {1, 2, 3, 4, 5};
    numeros.push_back(6);//usar si ya esta creado y lo deseas agregar
    numeros.emplace_back(7);// crea el objeto dentro del vector, no lo copia
    imprimirNumeros(numeros);
    numeros.pop_back();// elimina el ultimo elemento
    imprimirNumeros(numeros);
    numeros.erase(numeros.begin() +1, numeros.begin()+2);//erase borra desde un punto de inicio hasta un punto final
    imprimirNumeros(numeros);
    auto fin = numeros.end();// auto va a marcarme el ultimo item del vector(es para no ponerme a iterar todo el vector manualmente
    cout<< *fin<<endl;
    auto inicio = numeros.begin();
    cout<< *inicio;
    return 0;
}