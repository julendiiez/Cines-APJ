#ifndef _CINE_H
#define _CINE_H
#include "sala.h"
#include "sqlite3.h"

typedef struct{
    int codCine;
    char* ciudad;
    int precio;
}Cine;

int insertarCine(sqlite3 *db,int tamanyo);

#endif