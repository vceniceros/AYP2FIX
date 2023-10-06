//
// Created by ceni on 19/09/23.
//

#include "Punto.h"

Punto::Punto(double x, double y) {
    std::cout<<"nacio aca: "<<this<<std::endl;
    this->x = x;
    this->y = y;

}
//constructor de copia
Punto::Punto(const Punto &p) {
    std::cout<<"nacio copia aca: "<<this<<std::endl;
    this->x = p.x;
    this->y = p.y;
}


std::string Punto::to_str() {
    std::string  s = "(" + std::to_string(x) + ", ";
    s += std::to_string(y) + ")";
    return s;
}

Punto Punto::sumar(Punto p) {
    Punto aux(0, 0);
    aux.x = this->x +p.x;
    aux.y = this->y +p.y;
    return aux;
}
Punto Punto::operator+(Punto p) {
    Punto aux(0, 0);
    aux.x = this->x +p.x;
    aux.y = this->y +p.y;
    return aux;
}
double Punto::operator*(Punto p) {
    double aux = ((this->x)*(p.x) + (this->y)*(p.y));
    return aux;
}

Punto::~Punto() {
    std::cout<<"Muere en "<<this<<std::endl;

}
