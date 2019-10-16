#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "usuario.h"
#include <iterator>

using namespace std;

class Banco
{
public:
    Banco();

    void registrarUsuario(string cedula,string clave, float valor);
    void escribirArchivo();
    void consultarSaldo(string clave);
    void retirarDinero(string clave);

    map <string,Usuario> getUsuarios();

private:
    map <string,Usuario> usuarios;
};

#endif // BANCO_H
