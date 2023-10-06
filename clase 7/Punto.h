//
// Created by ceni on 19/09/23.
//

#ifndef CLASE7_PUNTO_H
#define CLASE7_PUNTO_H

#include <iostream>

class Punto {
private:
    double x;
    double y;
public:
  //PRE:-
  //POST: Construye un objeto de tipo Punto con las coordenadas que van por parametro
  Punto(double x, double y);
    //PRE:-
    //POST: devuelve un string como punto de r2
    //constructor de copia
    Punto(const Punto &p);
  std::string to_str();
    //PRE:-
    //POST: suma p al parametro implicito y me lo devuelve
  Punto sumar(Punto);
  //sobrecarga del operador +
  Punto operator+(Punto p);
  double operator*(Punto p);

  ~Punto();
};


#endif //CLASE7_PUNTO_H
