#include "persona.h"

Persona::Persona(int edad, string nombre, fecha_t fecha_nacimiento)
{
  this -> edad = edad;
  this -> nombre = nombre;
  this -> fecha_nacimiento = fecha_nacimiento;
}

void Persona::incrementar_edad()
{
  edad++;
}

void Persona::incrementar_edad(fecha_t fecha_actual)
{
  if(fecha_actual.mes == fecha_nacimiento.mes && fecha_actual.dia == fecha_nacimiento.dia){
    edad++;
  }
}

bool Persona::es_mayor(Persona * otra_persona)
{
  return !(otra_persona -> es_mayor(fecha_nacimiento));
}

bool Persona::es_mayor(fecha_t fecha_nacimiento)
{
  if(this -> fecha_nacimiento.anio < fecha_nacimiento.anio){
    return true;
  if((this -> fecha_nacimiento.anio == fecha_nacimiento.anio) && (this -> fecha_nacimiento.mes < fecha_nacimiento.mes))
    return true;
  if((this -> fecha_nacimiento.anio == fecha_nacimiento.anio) && (this -> fecha_nacimiento.mes == fecha_nacimiento.mes) && (this -> fecha_nacimiento.dia < fecha_nacimiento.dia))
    return true;
  }
  return false;
}

bool Persona::tiene_mismo_nombre(string nombre)
{
  return (this -> nombre == nombre);
}

bool Persona::es_misma_fecha(fecha_t fecha_nacimiento)
{
  return((this -> fecha_nacimiento.dia == fecha_nacimiento.dia)  && (this -> fecha_nacimiento.mes == fecha_nacimiento.mes) && (this -> fecha_nacimiento.anio == fecha_nacimiento.anio));
}

bool Persona::es_misma_persona(Persona* persona)
{
    return persona -> es_misma_persona(nombre, fecha_nacimiento);
}

bool Persona::es_misma_persona(string nombre, fecha_t fecha_nacimiento)
{
  return (es_mismo_nombre(nombre) && es_misma_fecha(fecha_nacimiento));
}
