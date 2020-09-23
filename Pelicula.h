//p nombre categoria duracion calificacion id 

using namespace std;

#include <iostream>
#include "Video.h"
class Pelicula: public Video
{
public:

Pelicula();
Pelicula(std::string nombre, std::string categoria, int duracion, int calificacion, int id);

void print();
void printFiltro(char filtro, int calificacion, std::string genero);

};

Pelicula::Pelicula(){}
Pelicula::Pelicula(std::string nombre, std::string categoria, int duracion, int calificacion, int id):Video(nombre, categoria, duracion, calificacion, id){}

void Pelicula::print()
{
cout<<"Nombre: "<< nombre<<endl;
cout<<"Categoria: "<< categoria<<endl;
cout<<"Duracion: "<< duracion<<endl;
cout<<"Calificación: "<< calificacion<<endl;
cout<<"id: "<< id<<endl;
cout<<endl;
}

void Pelicula::printFiltro(char filtro, int calificacion, std::string genero)
{

switch(filtro){

  case 'c':
    if(this->calificacion == calificacion)
    {
      cout<<"Nombre: "<< nombre<<endl;
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
      cout<<"Nombre: "<< nombre<<endl;
      cout<<"Categoria: "<< categoria<<endl;
      cout<<"Duracion: "<< duracion<<endl;
      cout<<"Calificación: "<< calificacion<<endl;
      cout<<"id: "<< id<<endl;
      cout<<endl;
    }
  break;

  default:

  break;

}
}