#include "sala.h"
#include <iostream>
#include "pelicula.h"

Sala::Sala(){
    this->codSala=0;
    this->codCine=0;
    this->fila=0;
    this->columna=0;
    this->pelis=new Pelicula[4];
    
}
Sala::Sala(int codSala,int codCine,int fila,int columna,int** dimension,Pelicula *pelis){
    this->codSala=codSala;
    this->codCine=codCine;
    this->fila=fila;
    this->columna=columna;
    this->pelis=pelis;
    this->pelis=new Pelicula[4];
    for(int i=0;i<4;i++){
        this->pelis[i]=pelis[i];
    }
}
Sala::~Sala(){
    delete[] pelis;
}
Sala::Sala(const Sala& s){
    this->codSala=s.getCodSala();
    this->codCine=s.getCodCine();
    this->fila=s.getFila();
    this->columna=s.getColumna();
    this->pelis=s.getPelis();

}
int Sala::getCodSala() const{
    return this->codSala;
}
int Sala::getCodCine() const{
    return this->codCine;
}
int Sala::getFila() const{
    return this->fila;
}
int Sala::getColumna() const{
    return this->columna;
}

Pelicula* Sala::getPelis() const{
    return this->pelis;
}
void Sala::setCodSala(int codSala){
    this->codSala=codSala;
}
void Sala::setCodCine(int codCine){
    this->codCine=codCine;
}
void Sala::setFila(int fila){
    this->fila=fila;
}
void Sala::setColumna(int columna){
    this->columna=columna;
}

void Sala::setPelis(Pelicula* pelis){
     for(int i=0;i<4;i++){
        this->pelis[i]=pelis[i];
    }
}
Sala& Sala::operator=(const Sala &s){
    this->codSala=s.getCodSala();
    this->codCine=s.getCodCine();
    this->fila=s.getFila();
    this->columna=s.getColumna();
    this->pelis=s.getPelis();
    return *this;
}


