#ifndef c11
#define c11

#include <iostream>
#include <string>
using namespace std;

class RelojD
{

public:

    //	👩‍🏭👨‍🏭Constructores
    RelojD();
    RelojD(int iHr, int iMin);

    //	💃🏻🕺🏽métodos
    string muestra();
    void incrementaMinutos();

    //	🎮 🔏métodos	de	Modificadores
    void setHora(int iHr);
    void setMin(int iMin);

    //	💳 🔓 métodos	de	Acceso
    int getHora();
    int getMin();

private:
    int iHora, iMins;

};

// Crea un reloj con los valores en 0 en caso que no sean introducidos
RelojD::RelojD()
{
    iHora = 0;

    iMins = 0;
}

// Crea un reloj con los valores introducidos validando que no sean valores invalidos
RelojD::RelojD(int iHr, int iMin)
{
    if (iHr <= 23 && iHr >= 0) {
        this->iHora = iHr;
    }
    else {
        iHora = 0;
    }
    if (iMin <= 59 && iMin >= 0) {
        this->iMins = iMin;
    }
    else {
        iMin = 0;
    }
}

// Cambia la variable de hora privada
void RelojD::setHora(int iHr) {
    if (iHr <= 23 && iHr >= 0) {
        this->iHora = iHr;
    }
}

// Cambia la variable de minutos privados
void RelojD::setMin(int iMin) {
    if (iMin <= 59 && iMin >= 0) {
        this->iMins = iMin;
    }
}

// Regresa la variable de hora
int RelojD::getHora() {
    return iHora;
}

// Regresa la variable de minutos
int RelojD::getMin() {
    return iMins;
}

string RelojD::muestra() {
    return to_string(iHora) + ":" + to_string(iMins) + "\n";

}

void RelojD::incrementaMinutos() {
    if (iMins < 59) {
        iMins++;
    }
    else {
        iMins = 0;
        if (iHora < 23) {
            iHora++;
        }
        else {
            iHora = 0;
        }
    }
}


#endif
