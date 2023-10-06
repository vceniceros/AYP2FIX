#include <iostream>
#include "Punto.h"
using namespace std;
int main() {
    Punto A(3, -2.5);
    Punto B = A;
    cout<<"A = "<<A.to_str()<<endl;
    /*Punto B(2, 3.5);
    Punto C(0,0);
    Punto* D;
    if(true){
        cout<<"Hola soy d"<<endl;
        D = new Punto(0, 0);
    }
    double E;
    C = A.sumar(B);
    E = A * B;
    cout<<"C = "<<C.to_str()<<endl;
    cout<<"E = "<<E<<endl;
    cout<<"se murio d"<<endl;
    delete D;
    */return 0;
}
