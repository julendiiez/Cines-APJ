#ifndef CINE_H
#define CINE_H
#include <stdio.h>
#include "sala.h"
#include "sqlite3.h"

typedef struct{
    int codCine;
    int precio;
    char *ciudad;
    Sala *salas;
} Cine;


int insertarCine(sqlite3 *db,int tamanyo, Cine *cines,int maxSala);
int insertarSalaACine(sqlite3 *db,int tamanyoCines,int maxSala,Cine *cines);
int insertarPeliculaASala(sqlite3 *db,int tamanyoCines,Cine *cines, Pelicula *peliculas,int maxPeli);


#endif