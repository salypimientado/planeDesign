#ifndef 19
#define 19
#include <string>
#include <iostream>
#include "RelojD.h"
#include "Fecha.h"

using namespace std;

class Vuelo
{

public:

	Vuelo();
	Vuelo(Fecha fFe, RelojD rRolex, string sDes, string sAero, int iPre, int iDis, int iNAsi, string iArch);

	void setFecha(Fecha fFe);
	void setHora(RelojD rolex);
	void setDestino(string sDes);
	void setAerolinea(string sAero);
	void setPrecio(int iPre);
	void setDistancia(int iDis);
	void setiNAsientos(int iNAsi);
	void setAsiento(int iFila, int iAsiento, int iCNum);
	void setArchivo(string sArch);

	int getPrecio();
	int getDistancia();
	int getNAsientos();
	int getAsiento(int iFila, int iAsiento);

	string getDestino();
	string getAerolinea();
	string getArchivo();

	Fecha getFecha();

	RelojD getHora();

	string str();
	void dispAsientos();

private:

	Fecha fFecha;
	RelojD rReloj;
	string sDestino;
	string sAerolinea;
	int iPrecio;
	int iDistancia;
	int iNAsientos;
	string sArchivoA;
	int iAsientos[30][4];

};

// Constructores
Vuelo::Vuelo() 
{
	RelojD rolex;
	Fecha fDef;
	fFecha = fDef;
	rReloj= rolex;
	sDestino = "Pais de nunca jamas(NJM)";
	sAerolinea = "PeterPairlines";
	iPrecio = 0;
	iDistancia = 999999;
	iNAsientos = 120;
	sArchivoA = "default.txt";
	iAsientos[30][4];
}
Vuelo :: Vuelo(Fecha fFe, RelojD rRolex, string sDes, string sAero, int iPre, int iDis, int iNAsi, string iArch) 
{
	this->fFecha = fFe;
	this->rReloj = rRolex;
	this->sDestino = sDes;
	this->sAerolinea = sAero;
	this->iPrecio = iPre;
	this->iDistancia = iDis;
	this->iNAsientos = iNAsi;
	this->sArchivoA = iArch;
	iAsientos[30][4];
}

//Setters
void Vuelo::setFecha(Fecha fFe) { this->fFecha = fFe; }
void Vuelo::setHora(RelojD rolex) { this->rReloj = rolex; }
void Vuelo::setDestino(string sDes) { this->sDestino = sDes; }
void Vuelo::setAerolinea(string sAero) { this->sAerolinea = sAero; }
void Vuelo::setPrecio(int iPre) { this->iPrecio = iPre; }
void Vuelo::setDistancia(int iDis) { this->iDistancia = iDis; }
void Vuelo::setiNAsientos(int iNAsi) { this->iNAsientos = iNAsi; }
void Vuelo::setArchivo(string sArch) { this->sArchivoA = sArch; }
void Vuelo::setAsiento(int iFila, int iAsiento, int iCNum) {this->iAsientos[iFila][iAsiento] = iCNum;}

int Vuelo::getPrecio() { return iPrecio; }
int Vuelo::getDistancia() { return iDistancia; }
int Vuelo::getNAsientos() { return iNAsientos; }
int Vuelo::getAsiento(int iFila, int iAsiento) { return iAsientos[iFila][iAsiento]; }

string Vuelo::getDestino() { return sDestino; }
string Vuelo::getAerolinea() { return sAerolinea; }
string Vuelo::getArchivo() { return sArchivoA; }

Fecha Vuelo::getFecha() { return fFecha; }

RelojD Vuelo::getHora() { return rReloj; }

string Vuelo::str() { return "El vuelo va hacia: " + sDestino + ", cuesta " + to_string(iPrecio) + ", es el " + fFecha.imprime() + " a las " + rReloj.muestra() + ", es de la aerolinea " + sAerolinea + " y es de " + to_string(iDistancia) +  "km de distancia" "\n"; }
void Vuelo::dispAsientos() {

	for(int iX = 0; iX<30; iX++)
	{
	for(int iY = 0; iY<4; iY++)
	{
		cout << iAsientos[iX][iY] << " ";
	}
	cout << "\n";
	}
}

#endif