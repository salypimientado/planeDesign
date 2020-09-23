
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Vuelo.h"
#include "Fecha.h"
#include "RelojD.h"
#include "Cliente.h"
#include <stdio.h>
#include <sstream>

using namespace std;

vector<Vuelo> loadVuelos(vector<Vuelo> vuelos);
vector<int> busqueda(int iDia, int iMes, int iYear, vector<Vuelo> vuelos);
void cambiarArchivo(string sArch, Vuelo vuelo);
void print(vector<Vuelo> vuelo);
vector<Cliente> loadCliente(vector<Cliente> clientes);
void login(vector<Cliente> clientes, vector<Vuelo> vuelos);
void mainMenu(vector<Vuelo> vuelos, Cliente cliente);
bool check(Vuelo vuelo, Cliente cliente);
void guardarClientes(vector<Cliente> clientes);

int main()
{
    vector<Vuelo> vuelos(0);
    vector<Cliente> clientes(0);

   // numVuelos(vuelos);
    vector<Vuelo> vVuelos = loadVuelos(vuelos);
    vector<Cliente> cClientes = loadCliente(clientes);

    login(cClientes, vVuelos);

   vector<int> resultados =  busqueda(17, 12, 19, vVuelos);
   vVuelos[0].setAsiento(0,0,1000);
// cambiarArchivo(vVuelos[0].getArchivo(), vVuelos[0]);
// vVuelos[0].dispAsientos();
/* for(int x=0; x<resultados.size(); x++)
   {
       cout << vVuelos[resultados[x]].str() << endl;
   }*/

  // print(vuelos);
}

vector<Vuelo> loadVuelos(vector<Vuelo> vuelos) 
{
    ifstream archivoEntrada;
    
    int num = 0;
    vuelos.clear();
    RelojD rolex;
    Fecha hoy;
    string sEvento, sLinea, iInfo[8], sDest, sAero, sArch;
    int iDuracion, iPosSep, iR, iKm, iPre, iAs;
    int iFecha[3],iHora[3];
    archivoEntrada.open("vuelos.txt");
    if (archivoEntrada.fail())
        cout << "El archivo de vuelos no existe" << endl;
    else
        while (!archivoEntrada.eof())
        {
            getline(archivoEntrada, sLinea);
           // cout << sLinea << endl;
            iPosSep = sLinea.find(",");
            iInfo[0] = sLinea.substr(0, iPosSep);
            for (int iX = 0; iX < 3; iX++)
            {
                iPosSep = sLinea.find(":");
                if (iX == 2)
                {
                    iPosSep = 2;
                }
                iHora[iX] = stoi(sLinea.substr(0, iPosSep));
                sLinea.erase(0, iPosSep + 1);

            }
            for (int iF = 1; iF < 8; iF++)
            {
                if (iF == 1)
                {
                    for (int iM = 0; iM < 3; iM++)
                    {
                        if (iM == 2) {
                            iPosSep = sLinea.find(",");
                            iFecha[iM] = stoi(sLinea.substr(0, iPosSep));
                            sLinea.erase(0, iPosSep + 1);
                        }
                        else {
                            iPosSep = sLinea.find("/");
                            iFecha[iM] = stoi(sLinea.substr(0, iPosSep));
                            sLinea.erase(0, iPosSep + 1);
                        }
                    }
                }
                else {
                    iPosSep = sLinea.find(",");
                    iInfo[iF] = sLinea.substr(0, iPosSep);
                    sLinea.erase(0, iPosSep + 1);
                }


            }






            rolex.setHora(iHora[0]);
            rolex.setMin(iHora[1]);
            hoy.setDia(iFecha[0]);
            hoy.setMes(iFecha[1]);
            hoy.setYear(iFecha[2]);
            sDest = iInfo[2];
            sAero = iInfo[3];
            iPre = stoi(iInfo[4]);
            iKm = stoi(iInfo[5]);
            iAs = stoi(iInfo[6]);
            sArch = iInfo[7];
            Vuelo def(hoy, rolex, sDest, sAero, iPre, iKm, iAs, sArch);
            vuelos.emplace_back(def);

            fstream asientos;
            asientos.open(vuelos[num].getArchivo(), ios::in | ios:: out);
            bool bNc = false;
            if (asientos.fail())
            {
                bNc = true;

            }
            if (bNc == true){
                asientos.close();
                asientos.open(vuelos[num].getArchivo(), ios::in | ios::out | ios::app);
                for (int x = 0; x < 30; x++)
                {
                    asientos << "1000 1000 1000 1000 " << endl;
                }
                asientos.close();
            }
            else
            
            {
                for (int iH = 0; iH < 30; iH++) 
                {
                    getline(asientos, sLinea);
                    for(int iY = 0; iY< 4; iY++)
                    {
                        string f =sLinea.substr(0, 4);
                        
                        int i = stoi(f);
                        vuelos[num].setAsiento(iH, iY, i);
                        sLinea.erase(0, 5);
                        
                    }
                }
                asientos.close();
                //vuelos[num].dispAsientos();
            }

            
           // cout << vuelos[num].str() << endl;
          //  cout << to_string(num) << endl;
            num++;

        }



        return vuelos;

}

void cambiarArchivo(string sArch, Vuelo vuelo) 
{
    remove(sArch.c_str());
    fstream archivo;
    archivo.open(sArch, ios::in | ios::out | ios::app);

    for (int iX = 0; iX < 30; iX++)
    {
        for (int iY = 0; iY < 4; iY++)
        {
            archivo << to_string(vuelo.getAsiento(iX, iY)) << " ";
        }
        archivo << "\n";
    }
    archivo.close();
}

vector<int> busqueda(int iDia, int iMes, int iYear, vector<Vuelo> vuelos) 
{
    
    Fecha busqueda(iDia, iMes, iYear);
    vector<int> iResultados;
    iResultados.clear();

    for(int x=0; x<vuelos.size(); x++)
    {
        Fecha vuelo = vuelos[x].getFecha();
        if(iDia == vuelo.getDia() && iMes == vuelo.getMes() && iYear == vuelo.getYear())
        {
            iResultados.emplace_back(x);
        }
    }
    return iResultados;
}

void print(vector<Vuelo> vuelo)
{
    for (int x = 0; x < vuelo.size(); x++)
    {
       cout << vuelo[x].str()<<endl;
    }
}

vector<Cliente> loadCliente(vector<Cliente> clientes) 
{
    ifstream aClientes;

    string sLinea, iInfo[6], sNombre, sCelular, sUser, sPass, sNum;
    int iPosSep, km;
    int num = 0;

    aClientes.open("clientes.txt");
    if (aClientes.fail())
        cout << "El archivo de vuelos no existe" << endl;
    else
        while (!aClientes.eof())
        {
            getline(aClientes, sLinea);
           //  cout << sLinea << endl;
            
            for (int iN = 0; iN < 6; iN++) 
            {
                iPosSep = sLinea.find("?");
                iInfo[iN] = sLinea.substr(0, iPosSep);
                sLinea.erase(0, iPosSep + 1);
            }

            sNombre = iInfo[0];
            sCelular = iInfo[1];
            sUser = iInfo[2];
            sPass = iInfo[3];
            km = stoi(iInfo[4]);
            sNum = iInfo[5];

            Cliente def(sNombre, sCelular, sUser, sPass, km, sNum);
            clientes.emplace_back(def);

            num++;
        }
    return clientes;
}

void login(vector<Cliente> clientes, vector<Vuelo> vuelos)
{
    string input;
    cout << "Introduzca su nombre de usuario" << endl;
    cin >> input;

    for (int iZ = 0; iZ < clientes.size(); iZ++) 
    {
        string user = clientes[iZ].getUsername();
        

        if (user == input) 
        {
        
            cout << "Introduzca su contraseña" << endl;
            cin >> input;

            string pass = clientes[iZ].getPassword();
            if (pass == input)
            {
                cout << "Ingreso correctamente. \nSeleccione 1 para comprar un boleto o 2 para ver sus datos personales" << endl;
                int i;
                cin >> i;
                if (i == 1){
                    mainMenu(vuelos, clientes[iZ]);
                    guardarClientes(clientes);
                    clientes = loadCliente(clientes);
            }
                if (i == 2) {
                     cout << clientes[iZ].str()<< endl;
                }
                login(clientes, vuelos);
            }
            else {
                cout << "Contraseña incorrecta" << endl;
                login(clientes, vuelos);
            }
            
        }

    }
    cout << "Este usuario no existe, vuelva a intentarlo\n" << endl;

    login(clientes, vuelos);
}

void mainMenu(vector<Vuelo> vuelos, Cliente cliente)
{
    cout << "¿En que fecha quiere su vuelo?" << endl;
    cout << "Ingrese el dia: ";
    int iDia, iMes, iYear;
    cin >> iDia;
    cout << "Ingrese el mes: ";
    cin >> iMes;
    cout << "Ingrese el año: ";
    cin >> iYear;
    vector<int> resultados = busqueda(iDia, iMes, iYear, vuelos);

    for (int iN = 0; iN < resultados.size(); iN++) {
        cout << vuelos[resultados[iN]].str() << endl;
        cout << "Numero de indice: " << resultados[iN] << endl;
    }
    cout << "Escriba el numero del vuelo que quiere elegir: ";
    int eleccion;
    cin >> eleccion;
    int fila, columna;
    vuelos[eleccion].dispAsientos();
    do {
        vuelos[eleccion].dispAsientos();
        cout << "Escoja una fila desde 1 a 30 (cada 1000 es un asiento libre)\n" << endl;

        cin >> fila;
        cout << "Escoja una columna desde 1 a 4(cada 1000 es un asiento libre)\n" << endl;
        cin >> columna;

        if (fila == -1 && columna == -1)
        {
            if (check(vuelos[eleccion], cliente))
            {
                cout << "Acaba de cancelar su vuelo" << endl;
                cliente.addKm(0 - vuelos[eleccion].getDistancia());
            }
            else
            {
                break;
            }
        }
        else{
        if (!(fila <= 30 && fila >= 1 && columna >= 1 && columna <= 4))
        {
            cout << "Campo no valido" << endl;
        }
    }
    } while ((fila > 30 && fila < 1 && columna < 1 && columna > 4 && vuelos[eleccion].getAsiento(fila - 1, columna - 1) != 1000));
    if (vuelos[eleccion].getAsiento(fila - 1, columna - 1) == 1000) {
        vuelos[eleccion].setAsiento(fila - 1, columna - 1, stoi(cliente.getCliente()));
        cambiarArchivo(vuelos[eleccion].getArchivo(), vuelos[eleccion]);
        cout << "Acaba de comprar un boleto" << endl;
        vuelos = loadVuelos(vuelos);
        cliente.addKm(vuelos[eleccion].getDistancia());
    }
    else {
        if (fila != -1 && columna != -1) {
            cout << "Ese lugar esta ocupado" << endl;
        }
    }

        
}

bool check(Vuelo vuelo, Cliente cliente) 
{
    int i = 0;
    int u = 0;
    bool t = false;
    for (int iM = 0; iM < 30; iM++)
    {
        for(int iY = 0; iY < 4; iY++)
        {
            i = vuelo.getAsiento(iM, iY);
            u = stoi(cliente.getCliente());
            if (i == u) 
            {
                vuelo.setAsiento(iM, iY, 1000);
                t = true;
                cambiarArchivo(vuelo.getArchivo(), vuelo);
            }
        }


    }
    
    return t;
}

void guardarClientes(vector<Cliente> clientes) 
{
    string a = "clientes.txt";
    fstream archivo;
    remove(a.c_str());
    archivo.open("clientes.txt", ios::in | ios::out | ios::app);
    
    for(int h = 0; h< clientes.size()-1; h++)
    {
        string name, cell, acc, pass, nCl;
        int km;

        name = clientes[h].getNombre();
        cell = clientes[h].getCelular();
        acc = clientes[h].getUsername();
        pass = clientes[h].getPassword();
        nCl = clientes[h].getCliente();
        km = clientes[h].getKm();

        archivo << name << "?" << cell << "?" << acc << "?" << pass << "?" << to_string(km) << "?" << nCl << "\n";
        
        
    }

    string name, cell, acc, pass, nCl;
    int km;

    name = clientes[clientes.size()-1].getNombre();
    cell = clientes[clientes.size() - 1].getCelular();
    acc = clientes[clientes.size() - 1].getUsername();
    pass = clientes[clientes.size() - 1].getPassword();
    nCl = clientes[clientes.size() - 1].getCliente();
    km = clientes[clientes.size() - 1].getKm();

    archivo << name << "?" << cell << "?" << acc << "?" << pass << "?" << to_string(km) << "?" << nCl << "";

    archivo.close();
}