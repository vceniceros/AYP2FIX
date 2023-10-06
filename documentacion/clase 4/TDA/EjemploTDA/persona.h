#include<iostream>
#include <string>

using namespace std;

typedef struct fecha{
  unsigned int dia;
  unsigned int mes;
  unsigned int anio;
}fecha_t;

class Persona {

private:

  int edad;
  string nombre;
  fecha_t fecha_nacimiento;

public:

  Persona(int edad, string nombre, fecha_t fecha_nacimiento);
  void incrementar_edad();
  void incrementar_edad(fecha_t fecha_actual);
  bool es_mayor(Persona * otra_persona);
  bool es_mayor(fecha_t fecha_nacimiento);
  bool tiene_mismo_nombre(string nombre);
  bool es_misma_persona(string nombre, fecha_t fecha_nacimiento);
  bool es_misma_persona(Persona * persona);
  bool es_misma_fecha(fecha_t fecha_nacimiento);

};
