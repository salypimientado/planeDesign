#ifndef cod17
#define cod17
#include <string>
#include <iostream>

using namespace std;

class Cliente
{

public:

	Cliente();
	Cliente(string sNom, string sCel, string sUser, string sPass, int iK, string sCliente);

	void setNombre(string sNom);
	void setCel(string sCel);
	void setUser(string sUser);
	void setPass(string sPass);
	void addKm(int iK);

	//Este valor es para ponerlo en los archivos de los aviones para identificar a quienes van sentados en cuales partes
	void setNCliente(string sCliente);

	string getNombre();
	string getCelular();
	string getUsername();
	string getPassword();
	string getCliente();
	string str();
	int getKm();


private:
	//nombre, celular, username, contraseña, km
	string sNombre;
	string sCelular;
	string sUsername;
	string sPassword;
	string sCliente;
	int iKm;
	

};

Cliente :: Cliente()
{
	sNombre = "Pancho";
	sCelular = "000-000-0000";
	sUsername = "Default";
	sPassword = "password";
	sCliente = "1100";
	iKm = 0;
}
Cliente :: Cliente(string sNom, string sCel, string sUser, string sPass, int iK, string sCli) 
{
	this -> sNombre = sNom;
	this -> sCelular = sCel;
	this -> sUsername = sUser;
	this -> sPassword = sPass;
	this -> sCliente = sCli;
	this -> iKm = iK;
}

void Cliente::setNombre(string sNom) { this->sNombre = sNom; }
void Cliente::setCel(string sCel) { this->sCelular = sCel; }
void Cliente::setUser(string sUser) { this->sUsername = sUser; }
void Cliente::setPass(string sPass) { this->sPassword = sPass; }
void Cliente::addKm(int iK) { this->iKm = iKm + iK; }
void Cliente::setNCliente(string sCli) { this->sCliente = sCli; }

string Cliente::getNombre() { return sNombre; }
string Cliente::getCelular() { return sCelular; }
string Cliente::getUsername() { return sUsername; }
string Cliente::getPassword() { return sPassword; }
string Cliente::getCliente() { return sCliente; }
string Cliente::str() 
{
	return "Nombre: " + sNombre + "\n Numero de telefono: " + sCelular + "\n Nombre de usuario: " + sUsername + "\n Clave de accesso: " + sPassword + "\n Numero de cliente: " + sCliente + "\n Kilometros: " + to_string(iKm);
}
int Cliente::getKm() { return iKm; }
#endif