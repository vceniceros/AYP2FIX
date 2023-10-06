//
// Created by valen on 25/8/2023.
//
#include <iostream>
using namespace std;
bool esPrimo(int numero){
    bool resultado = true;
    int i = 1;
    while(i <=numero){
        if(numero % i == 0 && i != 1 && i != numero){
            resultado = false;
        }
        i++;
    }
    return resultado;
}
int main() {
    int x;
    cout<<"ingrese un numero: "<<endl;
    cin >> x;
    if(esPrimo(x)){
        cout<<"el numero es primo";
    }else{
        cout<<"el numero no es primo";
    }
    return 0;
}