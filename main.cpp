#include <iostream>
#include <string>
#include <fstream>
#include "banco.h"

using namespace std;

bool compararClave(string clave);

int main()
{
    int opcion = 0;
    string clave;
    string usuario;

    Banco banco;
        cout << "Opcion de inicio" << endl <<"1. Administrador\n" << "2. usuario\n" << "Ingrese opcion: ";
        cin >> opcion;

    switch (opcion)
    {
    case 1:
        clave ="";
        cout << "Ingrese su clave de administrador:_";
        cin >> clave;
        if (compararClave(clave))
        {

        }
        else
        {
            cout << "\nclave incorrecta"<< endl;
        }
        break;
    case 2:
        usuario ="";
        cout << "Ingrese su cedula: ";
        cin >> usuario;
        clave ="";
        cout << "Ingrese su clave: ";
        cin >> clave;
        if (banco.getUsuarios()[usuario].getClave() == clave)
        {
            cout << "Opciones\n" << endl <<"1. Ver saldo\n" << "2. Retirar\n" << "Ingrese opcion: ";
            opcion = 0;
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                banco.consultarSaldo(usuario);
                break;
            case 2:
                banco.retirarDinero(usuario);
                break;
            }
        }
        else
        {
            cout << "\nUsuario o clave incorrecta"<< endl;
        }
    }

    banco.escribirArchivo();
    return 0;
}

bool compararClave(string clave)
{
    bool valor = false;

    string texto = "";
    ifstream archivo;
    archivo.open("sudo.txt", ios::in); //Abriendo archivo en modo lectura

    if (archivo.fail())
    {
        cout << "No se puede abrir archivo" << endl;
    }

    else
    {
        while (!archivo.eof())
        {
            getline(archivo,texto);
            if (clave == texto)
            {
                valor = true;
            }

        }

        archivo.close();
    }

    return valor;
}
