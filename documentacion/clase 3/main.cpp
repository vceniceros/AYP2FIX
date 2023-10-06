#include <iostream>
#include <vector>
#include <string>

using namespace  std;

void imprimirVectorEnteros(vector<int>& numeros) {
    cout << "Vector de enteros:";
    for (int num : numeros) {
        cout << " " << num;
    }
    cout << endl;
}


void imprimirVectorFrutas(vector<string>& frutas) {
    cout << "Vector de frutas:";
    for (const string& fruta : frutas) {
        cout << " " << fruta;
    }
    cout << endl;
}

int main() {

    vector<int> numeros = {1, 2, 3, 4, 5};

    vector<string> frutas;
    frutas.emplace_back("Manzana"); // Crea el objeto dentro del vector no lo copia

    string naranja = "Naranja";
    frutas.push_back(naranja); // Usar si ya tenes un objeto creado y deseas agregar una copia de este

    imprimirVectorEnteros(numeros);
    imprimirVectorFrutas(frutas);

    if (!numeros.empty()) {
        numeros.pop_back();  // Elimina el último elemento
        numeros.erase(numeros.begin() + 1, numeros.begin() + 3); //Elimina del segundo elemento al tercero
    }

    cout << "------------------------------------------------------" << endl;

    imprimirVectorEnteros(numeros);
    imprimirVectorFrutas(frutas);

    return 0;
}

