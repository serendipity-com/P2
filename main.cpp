#include <iostream>
#include <string>
#include <fstream>
#include "banco.h"

using namespace std;

bool compararClave(string clave);

int main()
{
    int opcion = 0;
    while (opcion == 0)
    {
        cout << "Opcion de inicio" << endl <<"1. Administrador\n" << "2. usuario\n" << "Ingrese opcion: ";
        cin >> opcion;
    }
    switch (opcion)
    {
    case 1:
        string clave ="";
        cout << "Ingrese su clave de administrador:_";
        cin >> clave;
        if (compararClave(clave))
        {
            Banco banco();
        }
        else
        {
            cout << "\nclave incorrecta"<< endl;
        }

    }

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
