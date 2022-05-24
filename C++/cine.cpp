#include <iostream>
#include "cine.h"
#include "sala.h"
#include <cstring>

#define MaxSala 5
using namespace std;
Cine::Cine(){
    this->codCine=0;
    this->precio=0;
    this->ciudad=new char[1];
    this->ciudad[0]='\0';
    this->salas=new Sala[MaxSala];
    
}
Cine::Cine(int codCine,int precio,char *ciudad,Sala *salas){
    this->codCine=codCine;
    this->precio=precio;
    this->ciudad=new char[strlen(ciudad)+1];
    strcpy(this->ciudad,ciudad);
    this->salas=new Sala[MaxSala];
    for(int i=0;i<MaxSala;i++){
        this->salas[i]=salas[i];
    }
}
Cine::~Cine(){
    delete[] ciudad;
    delete[] salas;
}
Cine::Cine(const Cine& c){
    this->codCine=c.getCodCine();
    this->precio=c.getPrecio();
    this->ciudad=new char[strlen(c.getCiudad())+1];
    strcpy(this->ciudad,c.getCiudad());
    this->salas=c.getSalas();


}
int Cine::getCodCine() const{
    return this->codCine;
}
int Cine::getPrecio() const{
    return this->precio;
}
char* Cine::getCiudad() const{
    return this->ciudad;
}
Sala* Cine::getSalas() const{
    return this->salas;
}
void Cine::setCodCine(int codCine){
    this->codCine=codCine;
}
void Cine::setPrecio(int precio){
    this->precio=precio;
}
void Cine::setCiudad(char* ciudad){
    delete[] this->ciudad;
    this->ciudad=new char[strlen(ciudad)+1];
    strcpy(this->ciudad,ciudad);
}
void Cine::setSalas(Sala* salas){
    //delete[] this->salas;
    //this->salas=new Sala[MaxSala];
    for(int i=0;i<MaxSala;i++){
        this->salas[i]=salas[i];
    }
}

