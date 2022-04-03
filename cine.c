#include <stdio.h>
#include "cine.h"
#include "sqlite3.h"
#include <stdlib.h>
#include <string.h>
#include "OPERACIONBD.h"
#define MaxLine 15


void clearIfNeeded(char *str, int max_line)
{

	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
		while (getchar() != '\n');
}
int insertarCine(sqlite3 *db,int tamanyo){
    Cine *c;
    c=(Cine*)malloc(sizeof(Cine));
    int precio;
    char opcion;
    char str[MaxLine];
    printf("Insertar la ciudad: \n");
    fflush(stdout);
    fgets(str,MaxLine,stdin);
    char *ciudad_fmt=malloc((MaxLine)*sizeof(char));
    sscanf(str, "%s", ciudad_fmt);
	int taman = strlen(ciudad_fmt);
	c->ciudad = malloc((taman + 1) * sizeof(char));
	strcpy(c->ciudad, ciudad_fmt);
	free(ciudad_fmt);
	clearIfNeeded(str, MaxLine);
    printf("Inserta el precio: \n");
    fflush(stdout);
    fgets(str,MaxLine,stdin);
    sscanf(str,"%i",&precio);
    clearIfNeeded(str,MaxLine);
    c->precio=precio;
    printf("%i\n",c->precio);
    printf("%s\n",c->ciudad);
    printf("Todos los datos han sido introducidos\n");
    while(opcion!='q'){
    printf("1.Confirmar\n");
    printf("2.Visualizar\n");
    printf("q.Cancelar\n");
    opcion=getchar();
    fflush(stdin);
    if(opcion=='1'){
      insertarDatosCine(db,tamanyo+1,c->ciudad,c->precio);
      opcion='q';
      return 1;

    }
    if(opcion=='2'){
        printf("Los datos del nuevo cine: %i, %s, %ieuros\n",tamanyo+1,c->ciudad,c->precio);
    }
    }
    return 0;
}



