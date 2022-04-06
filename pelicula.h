#ifndef PELICULA_H
#define PELICULA_H
#include "sqlite3.h"



typedef struct{
    int codPelicula;
    char* Titulo;
    char* Director;
    int duracion;
    char* idioma;
}Pelicula;







#endif