#ifndef CINE_H
#define CINE_H
#include <stdio.h>
#include "sala.h"
#include "sqlite3.h"

typedef struct{
    int codCine;
    int precio;
    char *ciudad;
}Cine;


int insertarCine(sqlite3 *db,int tamanyo, Cine *cines);
int insertarSalaACine(sqlite3 *db,int tamanyoCines,int maxSala,Cine *cines,Sala* salas);


#endif