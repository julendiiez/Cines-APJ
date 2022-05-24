#ifndef SALA_H
#define SALA_H
#include "pelicula.h"


class Sala{
private:
    int codSala;
    int codCine;
    int fila;
    int columna;
    Pelicula *pelis;
public:
    Sala();
    Sala(int codSala,int codCine,int fila,int columna,int** dimension,Pelicula *pelis);
    ~Sala();
    Sala(const Sala& s);
    Sala& operator=(const Sala &s);
    int getCodSala() const;
    int getCodCine() const;
    int getFila() const;
    int getColumna() const;
    Pelicula* getPelis() const;
    void setCodSala(int codSala);
    void setCodCine(int codCine);
    void setFila(int fila);
    void setColumna(int columna);
    void setPelis(Pelicula* pelis);

};

#endif