#include <iostream>
#include "vector.h"

using namespace std;

int main() {
    vector v(5);
    for(int i = 0; i < v.obtener_longitud();i++){
        v.insertar(i+1 , i);
    }
    for(int i = 0; i < v.obtener_longitud();i++){
        cout<< v.obetener(i)<<endl;
    }

    return 0;
}
