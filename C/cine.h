#ifndef CINE_H
#define CINE_H
#include <stdio.h>
#include "sala.h"
#include "sqlite3.h"

typedef struct Cine{
    int codCine;
    int precio;
    char *ciudad;
    struct Sala *salas;
} Cine;


int insertarCine(sqlite3 *db,int tamanyo, struct Cine *cines,int maxSala);
int insertarSalaACine(sqlite3 *db,int tamanyoCines,int maxSala,struct Cine *cines);
int insertarPeliculaASala(sqlite3 *db,int tamanyoCines,Cine *cines,struct Pelicula *peliculas,int maxPeli);
int borrarPeliculaSala(sqlite3 *db, int tamanyoCines, struct Cine *cine);
int leerFichero(sqlite3 *db,int tamanyoCines,int maxSala,struct Cine *cines);
int crearFichero(sqlite3 *db,int tamanyoCines,int maxSala,struct Cine *cines);

#endif