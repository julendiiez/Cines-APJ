#include "pelicula.h"
#include <iostream>
#include <cstring>

Pelicula::Pelicula(){
    this->codPelicula=0;
    this->titulo=new char[1];
    this->titulo[0]='\0';
    this->director=new char[1];
    this->director[0]='\0';
    this->horaComienzo=0;
    this->idioma=new char[1];
    this->idioma[0]='\0';
}
Pelicula::Pelicula(int codPelicula,char* titulo,char* director,int horaComienzo,char* idioma){
    this->codPelicula=codPelicula;
    this->titulo=new char[strlen(titulo)+1];
    strcpy(this->titulo,titulo);
    this->director=new char[strlen(director)+1];
    strcpy(this->director,director);
    this->horaComienzo=horaComienzo;
    this->idioma=new char[strlen(idioma)+1];
    this->idioma=idioma;
}
Pelicula::~Pelicula(){
    delete[] titulo;
    delete[] director;
    delete[] idioma;
}
Pelicula::Pelicula(const Pelicula& p){
    this->codPelicula=p.getCodPelicula();
    this->titulo=new char[strlen(p.getTitulo())+1];
    strcpy(this->titulo,p.getTitulo());
    this->director=new char[strlen(p.getDirector())+1];
    strcpy(this->director,p.getDirector());
    this->horaComienzo=p.getHoraComienzo();
    this->idioma=new char[strlen(p.getIdioma())+1];
    strcpy(this->idioma,p.getIdioma());

}

int Pelicula::getCodPelicula() const{
    return this->codPelicula;
}
char* Pelicula::getTitulo() const{
    return this->titulo;
}
char* Pelicula::getDirector() const{
    return this->director;
}
int Pelicula::getHoraComienzo() const{
    return this->horaComienzo;
}
char* Pelicula::getIdioma() const{
    return this->idioma;
}
void Pelicula::setCodPelicula(int codPelicula){
    this->codPelicula=codPelicula;
}
void Pelicula::setTitulo(char* titulo){
    delete[] this->titulo;
    this->titulo=new char[strlen(titulo)+1];
    strcpy(this->titulo,titulo);
}
void Pelicula::setDirector(char* director){
    delete[] this->director;
    this->director=new char[strlen(director)+1];
    strcpy(this->director,director);
}
void Pelicula::setHoraComienzo(int horaComienzo){
    this->horaComienzo=horaComienzo;
}
void Pelicula::setIdioma(char* idioma){
    delete[] this->idioma;
    this->idioma=new char[strlen(idioma)+1];
    strcpy(this->idioma,idioma);
}

Pelicula& Pelicula::operator=(const Pelicula &p){
    this->codPelicula=p.getCodPelicula();
    this->titulo=new char[strlen(p.getTitulo())+1];
    strcpy(this->titulo,p.getTitulo());
    this->director=new char[strlen(p.getDirector())+1];
    strcpy(this->director,p.getDirector());
    this->horaComienzo=p.getHoraComienzo();
    this->idioma=new char[strlen(p.getIdioma())+1];
    strcpy(this->idioma,p.getIdioma());
    return *this;

}