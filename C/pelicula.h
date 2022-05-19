#ifndef PELICULA_H
#define PELICULA_H
#include "sqlite3.h"
#include "cine.h"





typedef struct Pelicula{
    int codPelicula;
    char* Titulo;
    char* Director;
    int horaComienzo;
    char* idioma;
}Pelicula;


int insertarInforPelicula(sqlite3 *db,int MaxLine,int codPeli, struct Cine * cines,int posCine,int posSala, Pelicula *peliculas);





#endif