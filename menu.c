#include <stdio.h>
#include "OPERACIONBD.h"
#include "sqlite3.h"
#include <string.h>
#include "cine.h"
#include "sala.h"
#include <stdlib.h>

#define MaxCine 8
#define MaxSala 5


void menu(sqlite3 *db){
	printf("Bienvenido a cines APJ\n");
	char opcion;
	
	while(opcion!='q'){
		printf("1.Anyadir cines,\n");
		printf("2.Anyadir salas\n");
		printf("3.Anyadir pelicula a sala\n");
		printf("4.Configuracion\n");
		printf("5.Eliminar pelicula de sala\n");
		printf("r volver\n");
		printf("q salir\n");
		printf("Selecciona una opcion\n");
		scanf("%c",&opcion);
		fflush(stdin);
		if(opcion=='1'){
			if(insertarCine(db,contadorCine(db))!=0){
				printf("El cine se han introduciod correctamente");
			}

			
			
		}

	}
}
int main(void){	
	sqlite3 *db;
	sqlite3_open("CinesAPJ.db", &db);
	//Cine *cines=(Cine*)malloc(MaxCine*sizeof(Cine));
	//cines=listaDeCines(db);
	menu(db);
}