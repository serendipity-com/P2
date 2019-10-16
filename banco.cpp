#include "banco.h"

Banco::Banco()
{
    bool valorUsuario = true, valorClave = false;
    string usuario,clave,valor;

    string texto = "";
    ifstream archivo;
    archivo.open("datos.txt", ios::in); //Abriendo archivo en modo lectura

    if (archivo.fail())
    {
        cout << "No se puede abrir archivo" << endl;
    }

    else
    {
        while (!archivo.eof())
        {
            getline(archivo,texto);

            for (unsigned long long posicion = 0; posicion < texto.length(); posicion += 1)
            {
                if(texto[posicion] == 59){valorUsuario =false; valorClave = true;}
                if(texto[posicion] == 45){valorClave = false;}

                if (valorUsuario == true)
                {
                    usuario += texto[posicion];
                }
                else if (valorClave == true)
                {
                    clave += texto[posicion];
                }
                else
                {
                    valor += texto[posicion];
                }
            }
            Usuario devolver(usuario,clave, stof(valor));
            usuarios.insert({usuario,devolver});

        }

        archivo.close();
    }
}

void Banco::resgitarUsuario(string cedula, string clave, float valor)
{
    Usuario usuario(cedula, clave, valor);
    usuarios.insert({cedula,usuario});
}

void Banco::escribirArchivo()
{
    fstream archivo;

    archivo.open("datos.txt", ios::out);

    if(archivo.is_open())
    {
        for (auto posicion : usuarios)
        {
            archivo << posicion.first;
            archivo << ";";
            archivo << posicion.second.getClave();
            archivo << "-";
            archivo << posicion.second.getValor();
        }
        archivo.close();
    }
    else
    {
        cout <<"Error al crear el archivo "<<endl;
    }
}

map<string, Usuario> Banco::getUsuarios()
{
    return usuarios;
}
