//
// Created by valen on 25/8/2023.
//
#include <iostream>

using namespace std;
int factorial(int numero){
    int resultado = 1;
    for(int i = 1;i <= numero; i++){
        resultado *=  i;
    }
    return resultado;
}
int main(){
    int x;
    cout<<"ingrese un numero: "<<endl;
    cin >> x;
    int resultado = factorial(x);
    cout<<"el factorial de "<<x<<" es "<<resultado;
}