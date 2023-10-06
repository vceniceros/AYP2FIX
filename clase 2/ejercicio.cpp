//
// Created by ceni on 29/08/23.
//
#include <iostream>
#include <vector>

using namespace std;

void imprimirNumeros(vector<int>& numeros){// sin el & me hace una copia, no modifica al mismo vector
    for(int  i = 0; i < int(numeros.size()); i++){//size es largo del vector, size of es largo en bits
        cout<<numeros[i]<<endl;
    }
}
bool buscarNumero(vector<int>& numeros, int numero){
    bool resultado = false;
    for(size_t i = 0; i < numeros.size(); i++){//numeros.size
        if(numeros[i] == numero){
            resultado = true;
        }
    }
    return  resultado;
}
vector<int> vectorAleatorio(vector<int> & numeros_rand, int max){
    for(int i = 0; i < 10; i++){
        int numero_rand =::rand()%max;
        numeros_rand.push_back(numero_rand);
    }
    return  numeros_rand;
}
int main(){
    vector<int> numeros;
    vector<int> numeros_rand = vectorAleatorio(numeros, 51);
    imprimirNumeros(numeros_rand);
    bool esta = buscarNumero(numeros_rand, 3);
    if(esta){
        cout<<"esta"<<endl;
    }else{
        cout<<"no esta"<<endl;
    }
    auto tercero = numeros_rand.begin() + 3;
    numeros_rand.erase(tercero);
    imprimirNumeros(numeros_rand);
    return 0;
}