#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

class Usuario
{
public:
    Usuario();
    Usuario(string cedula,string clave,float valor);

    void setCedula();
    void setClave();
    void setValor();

    string getCedula();
    string getClave();
    float getValor();

private:
    string cedula;
    string clave;
    float valor;
};

#endif // USUARIO_H
