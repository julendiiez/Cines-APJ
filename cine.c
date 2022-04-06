#include <stdio.h>
#include "cine.h"
#include "sqlite3.h"
#include <stdlib.h>
#include <string.h>
#include "operacionBD.h"
#include "sala.h"
#include "pelicula.h"
#define MaxLine 15
#define MaxNum 10



void clearIfNeeded(char *str, int max_line)
{

	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
		while (getchar() != '\n');
}
int insertarCine(sqlite3 *db,int tamanyo,Cine *cines){
    Cine *c;
    c=(Cine*)malloc(sizeof(Cine));
    int precio;
    char opc;
    char str[MaxLine];
    printf("Insertar la ciudad: \n");
    fflush(stdout);
    fgets(str,MaxLine,stdin);
    char *ciudad_fmt=malloc((MaxLine)*sizeof(char));
    sscanf(str, "%s", ciudad_fmt);
	int taman = strlen(ciudad_fmt);
	c->ciudad = malloc((taman + 1) * sizeof(char));
	strcpy(c->ciudad, ciudad_fmt);
    c->ciudad[taman]='\0';
	free(ciudad_fmt);
	clearIfNeeded(str, MaxLine);
    printf("Inserta el precio: \n");
    fflush(stdout);
    fgets(str,MaxLine,stdin);
    sscanf(str,"%i",&precio);
    clearIfNeeded(str,MaxLine);
    c->precio=precio;
    c->codCine=tamanyo+1;
    printf("Todos los datos han sido introducidos\n");
    while(opc!='q'){
        printf("1.Confirmar\n");
        printf("2.Visualizar\n");
        printf("q.Cancelar\n");
        opc=getchar();
        fflush(stdin);
        if(opc=='1'){
            printf("%i\n",c->codCine);
            int result=insertarDatosCine(db,tamanyo+1,c->ciudad,c->precio);
            cines[tamanyo].codCine= c->codCine;
            cines[tamanyo].ciudad=(char*)malloc((taman+1)*sizeof(char));
            cines[tamanyo].ciudad=strcpy(cines[tamanyo].ciudad,c->ciudad);
            cines[tamanyo].ciudad[taman]='\0';
            cines[tamanyo].precio=c->precio;
            return result;
        }
        if(opc=='2'){
            printf("Los datos del nuevo cine: %i, %s, %ieuros\n",tamanyo+1,c->ciudad,c->precio);
        }
    }
        if(opc=='q'){
            return 1;
    }
}

int insertarSalaACine(sqlite3 *db,int tamanyoCines,int maxSala,Cine *cines,Sala* salas){
    char str[MaxNum];
    int codCine=0;
    int fin=0;
    int result;
    for(int i=0;i<tamanyoCines;i++){
        printf("CodCine: %i, %s precio: %i euros\n",cines[i].codCine,cines[i].ciudad,cines[i].precio);
    }
    while(fin!=1)
    printf("Seleccione cine o q para volver\n");
    fflush(stdout);
    fgets(str,MaxNum,stdin);
    if(str[0]=='q'){
        return 0;
    }
    sscanf(str,"%i",&codCine);
    if(codCine>0 && codCine<=tamanyoCines){
       int totSalCine=cuentaSalasCine(db,codCine);
        int totSala=contadorSala(db);
         if(totSalCine<maxSala && totSalCine>0){
                salas[totSala].codcine=codCine;
                salas[totSala].codSala=totSala;
                result=insertarInforSala(db,codCine,maxSala,salas,MaxNum);
             if(result==1){
                 printf("Los datos se han introducido correctamente\n");
                 return 1;
             }else{
                 return 0;
             }
        
        }else{
            if(totSalCine==0){
                //cines[codCine-1].salas=(Sala*)malloc(maxSala*sizeof(Sala));
                //cines[codCine-1].salas[totSalCine].codcine=codCine;
                //cines[codCine-1].salas[totSalCine].codSala=totSala;
                Sala *salaA=(Sala*)malloc(sizeof(Sala));
                salaA->codcine=codCine;
                salaA->codSala=totSala;
                result=insertarInforSala(db,codCine,maxSala,salaA,MaxNum);
                if(result==1){
                    printf("Los datos se han introducido correctamente");
                    return 1;
                }else{
                    return 0;
                }

            }else{
                printf("Ya ha llegado al numero maximo de salas que se puede introducir\n");

            }
        }

    }else{
        printf("El codigo de cine introducido no existe\n");
    }
     
}


int insertarPeliculaASala(sqlite3 *db,int tamanyoCines,Cine *cines){
    char str[MaxNum];
    int codCine=0;
    int codSala=0;
    int fin=0;
    int result;
    for(int i=0;i<tamanyoCines;i++){
        printf("CodCine: %i, %s precio: %i euros\n",cines[i].codCine,cines[i].ciudad,cines[i].precio);
    }
    while(fin!=1)
    printf("Seleccione cine o q para volver\n");
    fflush(stdout);
    fgets(str,MaxNum,stdin);
    if(str[0]=='q'){
        return 0;
    }

    if(codCine>0 && codCine<=tamanyoCines){
        printf("Seleccione sala: ");
        fflush(stdout);
        fgets(str,MaxNum,stdin);
        sscanf(str,"%i",&codSala);
    }
    int cantSala=cuantaSalasCine(db,codCine);
    if(codSala>0 && codSala<=cantSala){

        Pelicula *peliculaA=(Pelicula*)malloc(sizeof(Pelicula));

        

         


    }






}


