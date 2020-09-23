#include <iostream>
#include <fstream>



#include "Pelicula.h"
#include "Capitulo.h"
//#include "Serie.h"

char printMenu(char op);
void addSerie(std::string serie, std::string series[],int num,int size);


int main() {
  ifstream datos;
  datos.open("datos.txt");
  std::string tipo, nombre, categoria, serie;
  int duracion, calificacion, id, numerocap, numerotemp, numvids, n = 0, np=0,nc=0, sn = 0;
  char op;

  //pelicula: p nombre categoria duracion calificacion id 
  //capitulo: s nombre categoria duracion calificacion id numerocap numerotemp serie
  datos>>numvids;
  Video *videos[numvids];
  Video *peliculas[numvids];
  Video *series[numvids];
  std::string seriesS[numvids];

  while(datos>>tipo)
  {
    if(tipo=="p")
    {
      datos>>nombre>>categoria>>duracion>>calificacion>>id;
      videos[n] = new Pelicula(nombre,categoria,duracion,calificacion,id);
      peliculas[np] = new Pelicula(nombre,categoria,duracion,calificacion,id);
      np++;
    }
    else
    {
      datos>>nombre>>categoria>>duracion>>calificacion>>id>>numerocap>>numerotemp>>serie;
      videos[n] = new Capitulo(nombre,categoria,duracion,calificacion,id,numerocap, numerotemp, serie);
      series[nc] = new Capitulo(nombre,categoria,duracion,calificacion,id,numerocap, numerotemp, serie);
      addSerie(serie, seriesS,sn++,numvids);

      nc++;
    }
    n++;
  }


  /*for(int x=0; x<numvids;x++)
  {
    videos[x]->print();
  }*/
  while(op !='0')
  {
    op = printMenu(op);
    switch(op)
    {
      case '1':{
        for(int x=0; x<np;x++)
          {
            peliculas[x]->print();
          }
      break;
      }
      case '2':{
      for(int x=0; x<nc;x++)
          {
            if(seriesS[x] != ""){
            cout<<seriesS[x]<<endl;
            }
          }
    }
      break;
      case '3':{
       int calificacion;
        cout<<"Introduzca una calificacion:";
        cin>>calificacion;
        for(int x=0; x<numvids;x++)
          {
           
            videos[x]->printFiltro('c', calificacion, "suspenso");
          }
      break;
    }
      case '4':{
      std::string genero;
        cout<<"Introduzca un genero:";
        cin>>genero;
        cout<<endl;
        for(int x=0; x<numvids;x++)
          {
           
            videos[x]->printFiltro('g', 0, genero);
          }
      }
      break;
      case '5':{
        std::string serie;
        cout<<"Introduzca una serie:";
        cin>>serie;
        cout<<endl;
      for(int x=0; x<nc;x++)
          {
            series[x]->printFiltro('s',0, serie);
          }
      }
      break;
      case '6':
        {
          int calificacion;
        cout<<"Introduzca una calificacion:";
        cin>>calificacion;
        cout<<endl;
          for(int x=0; x<np;x++)
          {
            peliculas[x]->printFiltro('c', calificacion,"default");
          }

        }
      break;
      
      case '7':
        {
          int calificacion;
        cout<<"Introduzca una calificacion:";
        cin>>calificacion;
        cout<<endl;
          for(int x=0; x<nc;x++)
          {
            series[x]->printFiltro('c', calificacion,"default");
          }

        }
      break;

      case '8':
        {
          std::string nombre;
        cout<<"Introduzca una pelicula:";
        cin>>nombre;
        cout<<endl;
          for(int x=0; x<np;x++)
          {
            if(peliculas[x]->GetNombre()== nombre)
            {
              peliculas[x]->print();
            }
          }

        }


      break;

      case '9':{
      std::string genero;
        cout<<"Introduzca un genero:";
        cin>>genero;
        cout<<endl;
        for(int x=0; x<np;x++)
          {
           
            peliculas[x]->printFiltro('g', 0, genero);
          }
      }
      default:
      break;
    }
  }
}

char printMenu(char op)
{
  cout<<endl;
cout<<"1. Mostrar la lista de películas"<<endl;
cout<<"2. Mostrar la lista de series"<<endl;
cout<<"3. Mostrar los videos en general con una cierta calificación"<<endl;
cout<<"4. Mostrar los videos en general de un cierto género"<<endl;
cout<<"5. Mostrar los episodios de una determinada serie con sus calificaciones"<<endl;
cout<<"6. Mostrar las películas con cierta calificación"<<endl;
cout<<"7. Mostrar los episodios en general con cierta calificación"<<endl;
cout<<"8. Mostrar una pelicula determinada"<<endl;
cout<<"9. Mostrar las películas de un cierto género"<<endl;
cout<<"0. Salir"<<endl;
cout<<"Seleccione una opcion:";
cin>>op;
cout<<endl;
return op;
}

void addSerie(std::string serie, std::string series[],int num,int size)
{
//1cout<<&series[-1];
bool exists = false;
for(int x = 0; x<=size;x++)
{
  if(series[x]==serie)
  {
    exists = true;
  }
}
//cout<<exists<<endl;
  if(!exists){series[num]=serie;}
}