#ifndef Video_h
#define Video_h

#include <iostream>
class Video
{
public:
Video();
Video(std::string nombre, std::string categoria, int duracion, int calificacion, int id);

std::string GetCategoria() {return categoria;}
void SetCategoria(std::string categoria) {categoria = categoria;}
std::string GetNombre() {return nombre;}
void SetNombre(std::string nombre) {nombre = nombre;}
int GetDuracion() {return duracion;}
void SetDuracion(int duracion) {duracion = duracion;}
int GetId() {return id;}
void SetId(int id) {id = id;}
int GetCalificacion() {return calificacion;}
void SetCalificacion(int calificacion) {calificacion = calificacion;}

virtual void print() = 0;
virtual void printFiltro(char, int, std::string) = 0;

protected:

std::string nombre, categoria;
int duracion, id, calificacion;

};



Video:: Video()
{
nombre = "default";
categoria = "default";
duracion = 0;
calificacion = 0;
id = 0;
}

Video :: Video(std::string nombre, std::string categoria, int duracion, int calificacion, int id)
{
this->nombre = nombre;
this->categoria = categoria;
this->duracion = duracion;
this->calificacion = calificacion;
this->id = id;

}

#endif