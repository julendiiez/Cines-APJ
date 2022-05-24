#ifndef CINE_H
#define CINE_H
#include <stdio.h>
#include "sala.h"


class Cine{
private:
    int codCine;
    int precio;
    char *ciudad;
    Sala *salas;
public:    
    Cine();
    Cine(int codCine,int precio,char *ciudad,Sala *salas);
    ~Cine();
    int getCodCine() const;
    int getPrecio() const;
    char* getCiudad() const;
    Sala* getSalas() const;
    void setCodCine(int codCine);
    void setPrecio(int precio);
    void setCiudad(char* ciudad);
    void setSalas(Sala* salas);
    Cine(const Cine& c);


    

};

#endif