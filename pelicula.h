#ifndef PELICULA_H
#define PELICULA_H
#include "sqlite3.h"
#include "cine.h"
#include "sala.h"




typedef struct{
    int codPelicula;
    char* Titulo;
    char* Director;
    int horaComienzo;
    char* idioma;
}Pelicula;


int insertarInforPelicula(sqlite3 *db,int MaxLine,int codPeli,Cine *cines,int posCine,int posSala,Pelicula *pelis);





#endif