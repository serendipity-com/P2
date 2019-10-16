#include "banco.h"

Banco::Banco()
{
    bool valorUsuario = true, valorClave = false;
    string cedula,clave,valor;

    string texto = "";
    ifstream archivo;
    archivo.open("datos.txt"); //Abriendo archivo en modo lectura

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
                else if(texto[posicion] == 45){valorClave = false;}

                else{
                if (valorUsuario == true)
                {
                    cedula += texto[posicion];
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
            }
            cout << cedula << " : "<< clave << " : "<< valor << endl;
            Usuario devolver(cedula,clave, stof(valor));
            usuarios.insert({cedula,devolver});

        }

        archivo.close();
    }
}

void Banco::registrarUsuario(string cedula, string clave, float valor)
{
    Usuario usuario(cedula, clave, valor);
    usuarios.insert({cedula,usuario});
    escribirArchivo();
}

void Banco::escribirArchivo()
{
    ofstream archivo;

    archivo.open("datos.txt");


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

void Banco::consultarSaldo(string cedula)
{
    float valor = usuarios[cedula].getValor();
    cout << "Su saldo es: " << valor;
    valor -= 1000;
    usuarios[cedula].modificarValor(valor);
}

void Banco::retirarDinero(string cedula)
{
    float cantidadRetiro = 0;
    cout << "Ingrese cantidad a retirar" << endl;
    cin >> cantidadRetiro;
    float saldo = usuarios[cedula].getValor();
    if(cantidadRetiro <= saldo)
    {
        saldo -= cantidadRetiro;
        saldo -= 1000;
        usuarios[cedula].modificarValor(saldo);
        escribirArchivo();
    }
    else{cout << "saldo insuficiente" << endl;}
}

map<string, Usuario> Banco::getUsuarios()
{
    return usuarios;
}
