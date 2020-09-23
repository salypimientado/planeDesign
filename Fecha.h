#ifndef c10
#define c10
#include <iostream>
#include <string>
using namespace std;

class Fecha
{

public:

    //	👩‍🏭👨‍🏭Constructores
    Fecha();
    Fecha(int iD, int iM, int iY);

    //	💃🏻🕺🏽métodos
    string mes();
    int diasMes();
    void diaSiguiente();
    string imprime();

    //	🎮 🔏métodos	de	Modificadores
    void setDia(int iD);
    void setMes(int iM);
    void setYear(int iY);

    //	💳 🔓 métodos	de	Acceso
    int getDia();
    int getMes();
    int getYear();

private:
    int iDia, iMes, iYear;

};

// Crea un reloj con los valores en 0 en caso que no sean introducidos
Fecha::Fecha()
{
    iDia = 1;

    iMes = 1;

    iYear = 1900;
}

// Crea una fecha con los valores introducidos validando que no sean valores invalidos y asignandolos a 1 si lo son
Fecha::Fecha(int iD, int iM, int iY)
{
    this->iYear = iY;
    if (iM == 1 || iM == 3 || iM == 5 || iM == 7 || iM == 8 || iM == 10 || iM == 12) {
        if (iD <= 31 && iD >= 1) {
            this->iDia = iD;
            this->iMes = iM;
        }
        else {
            this->iDia = 1;
            this->iMes = iM;
        }
    }
    else {
        if (iM == 2) {
            if (iYear % 4 == 0) {
                if (iD <= 29 && iD >= 1) {
                    this->iDia = iD;
                    this->iMes = iM;
                }
            }
            else {
                if (iD <= 28 && iD >= 1) {
                    this->iDia = iD;
                    this->iMes = iM;
                }

                else {
                    this->iDia = 1;
                    this->iMes = iM;
                }
            }
        }
        else {
            if (iM == 4 || iM == 6 || iM == 9 || iM == 11) {
                if (iD <= 30 && iD >= 1) {
                    this->iDia = iD;
                    this->iMes = iM;
                }
                else {
                    this->iDia = 1;
                    this->iMes = iM;
                }
            }
            else {
                this->iDia = 1;
                this->iMes = 1;
            }
        }

    }
};

// Cambia la variable privada de dia, comprobando que entre en la cantidad de dias del mes correspondiente
void Fecha::setDia(int iD) {
    if (iMes == 1 || iMes == 3 || iMes == 5 || iMes == 7 || iMes == 8 || iMes == 10 || iMes == 12) {
        if (iD <= 31 && iD >= 1) {
            this->iDia = iD;
        }
    }
    else {
        if (iMes == 2) {
            if (iYear % 4 == 0) {
                if (iD <= 29 && iD >= 1) {
                    this->iDia = iD;
                }
            }
            else {
                if (iD <= 28 && iD >= 1) {
                    this->iDia = iD;
                }
            }
        }
        else {
            if (iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11) {
                if (iD <= 30 && iD >= 1) {
                    this->iDia = iD;
                }
            }
        }
    }
}

// Cambia la variable privada de meses 
void Fecha::setMes(int iM) {
    if (iM <= 12 && iM >= 1) {
        this->iMes = iM;
    }
}

// Cambia la variable privada de años
void Fecha::setYear(int iY) {
    this->iYear = iY;

}

// Regresa la variable de dia
int Fecha::getDia() {
    return iDia;
}

// Regresa la variable de mes
int Fecha::getMes() {
    return iMes;
}

int Fecha::getYear() {
    return iYear;
}

string Fecha::imprime() {
    return to_string(iDia) + "/" + to_string(iMes) + "/" + to_string(iYear) + "\n";
}

void Fecha::diaSiguiente() {
    if (iMes == 2) {
        if (iDia < 28) {
            iDia++;
        }
        if (iDia == 28) {
            iDia = 1;
            if (iMes == 12) {
                iMes = 1;
                iYear++;
            }
            else {
                iMes++;
            }
        }
    }
    else {
        if (iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11) {
            if (iDia < 30) {
                iDia++;
            }
            else {
                if (iDia == 30) {
                    iDia = 1;
                    iMes++;
                }
            }
        }

        else {
            if (iMes == 1 || iMes == 3 || iMes == 5 || iMes == 7 || iMes == 8 || iMes == 10 || iMes == 12) {
                if (iDia < 31) {
                    iDia++;
                }
                if (iDia == 31) {
                    iDia = 1;
                    if (iMes == 12) {
                        iMes = 1;
                        iYear++;
                    }
                    else {
                        iMes++;
                    }
                }
            }
        }
    }
}

// Regresa el mes
string Fecha::mes() {
    int m = iMes;

    if (m == 1) {
        return "Enero";
    }
    if (m == 2) {
        return "Febrero";
    }

    if (m == 3) {
        return "Marzo";
    }

    if (m == 4) {
        return "Abril";
    }

    if (m == 5) {
        return "Mayo";
    }

    if (m == 6) {
        return "Junio";
    }

    if (m == 7) {
        return "Julio";
    }

    if (m == 8) {
        return  "Agosto";
    }

    if (m == 9) {
        return "Septiembre";
    }

    if (m == 10) {
        return "Octubre";
    }

    if (m == 11) {
        return "Noviembre";
    }

    if (m == 12) {
        return "Diciembre";
    }
    else {
        return "Nada";
    }
}

#endif