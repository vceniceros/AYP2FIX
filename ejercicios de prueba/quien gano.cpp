//
// Created by valen on 25/8/2023.
//
#include <iostream>
#include <string>
using namespace std;

int quienGano(int goles1, int goles2){
    int resultado = 0;
    if(goles1 > goles2){
        resultado = 1;
    }else if(goles2 > goles1){
        resultado = 2;
    }else{
        resultado = 3;
    }
    return resultado;
}
int tomarResultados(){
    int goles1;
    int goles2;
    int resultado;
    cout<<"ingrese los goles del primer equipo: "<<endl;
    cin >>goles1;
    cout<<"ingrese los goles del segundo equipo: "<<endl;
    cin >>goles2;
    resultado = quienGano(goles1,goles2);
    return resultado;
}
int main(){
    int resultado = tomarResultados();
    switch (resultado) {
        case 1:cout<<"gano el equipo 1";break;
        case 2:cout<<"gano el equipo 2";break;
        case 3:cout<<"empate";break;
        default:cout<< "invalida"   ;
    }
}