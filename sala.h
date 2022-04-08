#ifndef SALA_H
#define SALA_H
#include "sqlite3.h"
#include "cine.h"
#include "operacionBD.h"
#include "pelicula.h"


typedef struct{
    int codSala;
    int codcine;
    int fila;
    int columna;
    int **dimension;
    Pelicula *peli;
}Sala;

int insertarInforSala(sqlite3 *db,int codCine,int maxSala,Sala *sala, int MaxNum);


#endif