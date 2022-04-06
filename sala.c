#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include "operacionBD.h"
#include "sala.h"
#include "cine.h"
#include "pelicula.h"


int insertarInforSala(sqlite3 *db,int codCine,int maxSala,Sala *sala,int MaxNum){
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
            sala->fila=fila;
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
        if(columna>0 && columna<=15){
            sala->columna=columna;
            int inbd=insertarDatosSala(db,sala->codSala,sala->codcine,sala->fila,sala->columna);
            if(inbd==1){
                printf("En la base de datos se ha introducido correctamente\n");
            }else{
                printf("Ha ocurrido un error al insertar en la base de datos\n");
            }
            fin=1;
        }else{
            printf("El numero de columna introducido no es correcto\n");
        }

    }

    sala->dimension=(int**)malloc((sala->columna)*sizeof(int*));
    for(int i=0;i<sala->columna;i++){
        sala->dimension[columna]=(int*)malloc((sala->fila)*sizeof(int));

    }
    for(int i=0;i<sala->columna;i++){
        for(int j=0;j<sala->fila;j++){
            sala->dimension[i][j]=0;

        }
    }
    return 1;
}
