//
// Created by ceni on 24/08/23.
//
#include <iostream>
#include <vector>
using namespace std;
const int IVA = 21;
int minimo(int x, int y){
    int min = 0;
    if (x < y){
        min = 1;
    }
    return  min;
}


int main(){
    cout<<"hola mundo"<<endl;
    char caracter = 'a';
    int numero = 1;
    bool boleano = true;
    float numero_decimal = 4.5;
    double numero_decimal_largo = 4.5678;
    cout<<"esto es un caracter "<<caracter<<endl;
    cout<<"esto es un entero "<<numero<<endl;
    cout<<"esto es un boleano "<<boleano<<endl;
    cout<<"esto es un decimal 'corto' "<<numero_decimal<<endl;
    cout<<"esto es un decimal 'largo' "<<numero_decimal_largo<<endl;
    cout<<"esto es una constante "<<IVA<<endl;
    int vec[10];
    vec[0]= 5;
    cout<<"esto es el indice 0 del vector 0 "<<vec[0]<<endl;
    int matriz [3] [5];
    matriz [2] [4] = 5;
    cout<<"la matriz en la fila 2 columna 4 es " << matriz [2] [4]<<endl;
    // not = !
    // and = &&
    //|| = or
    // incremento = ++, pre incremento ++variable, post incremento variable++
    // decremento = -- mismo que arriba
    int prueba_de_if;
    cout<<"probemos los if"<<endl;
    cin >> prueba_de_if;
    if (prueba_de_if == 1){
        cout<<"probaste la opcion 1"<<endl;
    }else if(prueba_de_if == 2){
        cout<<"probaste la opcion 2"<<endl;
    }else{
        cout<<"probaste la opcion 3"<<endl;
    }
    cout<<"se viene un bucle sensual"<<endl;
    for(int i = 0;i <=10; i++){
        cout<<i<<endl;
    }
    int num1 = 3;
    int num2 = 2;
    int min = minimo(num1, num2);
    cout<<"el minimo es: "<<min<<endl;
    return 0;
}