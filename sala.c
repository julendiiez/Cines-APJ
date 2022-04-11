#include "sala.h"
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include "operacionBD.h"
#include "cine.h"
#include "pelicula.h"
#include <string.h>


int insertarInforSala(sqlite3 *db,int codCine,int posicion,struct Cine* cines,int MaxNum){
    char str[MaxNum];
    int fila;
    int columna;
    int fin=0;
    int totSalCine=cuentaSalasCine(db,codCine);
    int totSala=contadorSala(db);
    while(fin!=1){
        printf("Seleccione fila: Maximo: 15 o q para volver\n");
        fflush(stdout);
        fgets(str,MaxNum,stdin);
        if(str[0]=='q'){
            return 0;
        }
        sscanf(str,"%i",&fila);
        if(fila>0 && fila<=15){
            cines[posicion].salas[totSalCine].fila=fila;
            fin=1;

        }else{
            printf("El numero de fila introducido no es correcto\n");
        }
    }
    fin=0;
    while(fin!=1){
        printf("Seleccione columna: Maximo: 20 o q para volver\n");
        fflush(stdout);
        fgets(str,MaxNum,stdin);
        if(str[0]=='q'){
            return 0;
        }
        sscanf(str,"%i",&columna);
        if(columna>0 && columna<=20){
            cines[posicion].salas[totSalCine].columna=columna;
            cines[posicion].salas[totSalCine].codcine=codCine;
            cines[posicion].salas[totSalCine].codSala=(totSala+1);
            int inbd=insertarDatosSala(db,cines[posicion].salas[totSalCine].codSala,cines[posicion].salas[totSalCine].codcine,cines[posicion].salas[totSalCine].fila,cines[posicion].salas[totSalCine].columna);
            if(inbd==1){
                printf("En la base de datos se ha introducido correctamente\n");
                fin=1;
            }else{
                printf("Ha ocurrido un error al insertar en la base de datos\n");
                return 0;
            }
            
        }else{
            printf("El numero de columna introducido no es correcto\n");
        }
    }
    printf("b");
    cines[posicion].salas[totSalCine].pelis=(struct Pelicula*)malloc(4*sizeof(struct Pelicula));
    for(int i=0;i<4;i++){
        cines[posicion].salas[totSalCine].pelis[i].horaComienzo=0;
    }
    printf("c");
    cines[posicion].salas[totSalCine].dimension=(int**)malloc((cines[posicion].salas[totSalCine].columna)*sizeof(int*));
    for(int i=0;i<cines[posicion].salas[totSalCine].columna;i++){
        cines[posicion].salas[totSalCine].dimension[columna]=(int*)malloc((cines[posicion].salas[totSalCine].fila)*sizeof(int));
        printf("o");
    }
    for(int i=0;i<cines[posicion].salas[totSalCine].columna;i++){
        printf("z");
        for(int j=0;j<cines[posicion].salas[totSalCine].fila;j++){
            cines[posicion].salas[totSalCine].dimension[i][j]=0;
            printf("h");

        }
    }
    printf("a");
    return 1;
}