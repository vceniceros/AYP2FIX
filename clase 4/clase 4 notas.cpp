//
// Created by ceni on 07/09/23.
//
#include <iostream>
using namespace std;
int main(){
    int* mem = new int[5];//siempre tiene un asterico mas en el mem que en el int
    cout<<mem<<endl;
    delete[] mem;
    cout<<mem<<endl;
    return 0;
}

//siempre hacer delete a nullptr