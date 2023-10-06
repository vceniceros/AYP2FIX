//
// Created by ceni on 24/08/23.
//
#include <iostream>
#include <vector>
using namespace std;
vector<int> serieCollaz(int numero){
    vector <int> resultado = {};
    resultado.push_back(numero);
    while(numero > 1){
        if(numero % 2 == 0){
            numero /= 2;// la / es para dividir y el = es para asignar a numero el nuevo valor
        }else{
            numero = 3 * numero +  1;
        }
        resultado.push_back(numero);
    }
    return resultado;
}
int main(){
    //escribir una funcion que cuando reciba un numero mayor a 1 devuelva la serie de colaz como un vector
    vector<int> resultado = serieCollaz(100);
    cout<<"el resultado es ";
    for (int i=0; i<resultado.size(); i++){
        cout<<resultado[i] <<", "<<endl;
    }

    return 0;
}