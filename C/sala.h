#ifndef SALA_H
#define SALA_H
#include "sqlite3.h"
#include "cine.h"
#include "operacionBD.h"
#include "pelicula.h"


typedef struct Sala{
    int codSala;
    int codcine;
    int fila;
    int columna;
    int **dimension;
    struct Pelicula *pelis;
}Sala;




int insertarInforSala(sqlite3 *db,int codCine,int posicion,struct Cine* cines, int MaxNum);

#endif