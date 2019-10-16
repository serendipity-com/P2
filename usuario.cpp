#include "usuario.h"

Usuario::Usuario()
{

}

Usuario::Usuario(string cedula, string clave, float valor)
{
    this -> cedula = cedula;
    this -> clave = clave;
    this -> valor = valor;
}

string Usuario::getCedula()
{
    return  cedula;
}

string Usuario::getClave()
{
    return clave;
}

float Usuario::getValor()
{
    return valor;
}

void Usuario::modificarValor(float nuevoValor)
{
    valor = nuevoValor;
}


