//s nombre categoria duracion calificacion id numerocap numerotemp serie


#ifndef Capitulo_h
#define Capitulo_h

#include <iostream>
#include "Video.h"
class Capitulo: public Video
{
public:

Capitulo();
Capitulo(std::string nombre, std::string categoria, int duracion, int calificacion, int id, int numCap, int numTemp, std::string serie);

int GetNumCap() {return numCap;}
void SetNumCap(int numCap) {numCap = numCap;}
int GetNumTemp() {return numTemp;}
void SetNumTemp(int numTemp) {numTemp = numTemp;}
std::string getSerie(){return serie;}
void setSerie(std::string serie){this->serie = serie;}
void print();
void printFiltro(char filtro, int calificacion, std::string genero);

private:

int numCap, numTemp;
std::string serie;

};

Capitulo::Capitulo():Video()
{
  numCap = 1;
  numTemp = 1;
  serie = "default";
}

Capitulo::Capitulo(std::string nombre, std::string categoria, int duracion, int calificacion, int id, int numCap, int numTemp, std::string serie):Video(nombre, categoria, duracion, calificacion, id)
{
  this->numCap = numCap;
  this->numTemp = numTemp;
  this->serie = serie;
}

void Capitulo::print()
{
  if(numCap == 1 && numTemp ==1)
{
  cout<<"Serie: "<<serie<<endl;
  cout<<endl;
  cout<<"Temporada: "<<numTemp<<endl;
  cout<<endl;
}
if(numCap == 1 && numTemp !=1)
{
  cout<<"Temporada: "<<numTemp<<endl;
  cout<<endl;
}
cout<<"Capitulo "<<numCap<<": "<<nombre<< endl;
cout<<"Categoria: "<< categoria<<endl;
cout<<"Duracion: "<< duracion<<endl;
cout<<"Calificación: "<< calificacion<<endl;
cout<<"id: "<< id<<endl;
cout<<endl;


}

void Capitulo::printFiltro(char filtro, int calificacion, std::string genero)
{

switch(filtro){

  case 'c':
    if(this->calificacion == calificacion)
    {
      cout<<"Serie: "<<serie<<endl;
      cout<<"Temporada: "<<numTemp<<endl;
      cout<<"Capitulo "<<numCap<<": "<<nombre<< endl;
      cout<<"Categoria: "<< categoria<<endl;
      cout<<"Duracion: "<< duracion<<endl;
      cout<<"Calificación: "<< calificacion<<endl;
      cout<<"id: "<< id<<endl;
      cout<<endl;
    }
  break;

  case 'g':
     if(this->categoria == genero)
    {
      cout<<"Serie: "<<serie<<endl;
      cout<<"Temporada: "<<numTemp<<endl;
      cout<<"Capitulo "<<numCap<<": "<<nombre<< endl;
      cout<<"Categoria: "<< categoria<<endl;
      cout<<"Duracion: "<< duracion<<endl;
      cout<<"Calificación: "<< calificacion<<endl;
      cout<<"id: "<< id<<endl;
      cout<<endl;
    }
  break;

  case 's':
     if(this->serie == genero)
    {
       if(numCap == 1 && numTemp ==1)
{
  cout<<"Serie: "<<serie<<endl;
  cout<<endl;
  cout<<"Temporada: "<<numTemp<<endl;
  cout<<endl;
}
if(numCap == 1 && numTemp !=1)
{
  cout<<"Temporada: "<<numTemp<<endl;
  cout<<endl;
}
cout<<"Capitulo "<<numCap<<": "<<nombre<< endl;
cout<<"Categoria: "<< categoria<<endl;
cout<<"Duracion: "<< duracion<<endl;
cout<<"Calificación: "<< this->calificacion<<endl;
cout<<"id: "<< id<<endl;
cout<<endl;


    }
  break;
  default:

  break;
}
}

#endif