#include <stdio.h>
#include "operacionBD.h"
#include "sqlite3.h"
#include <string.h>
#include "cine.h"
#include "sala.h"
#include <stdlib.h>
#include "pelicula.h"

#define MaxCine 10
#define MaxSala 5
#define MaxLine 50


void menu(sqlite3 *db,Cine* cines){
	printf("Bienvenido a cines APJ\n");
	char opcion[10];
	int opc=0;
	
	while(opcion!="q"){
		printf("1.Anyadir cines\n");
		printf("2.Anyadir salas\n");
		printf("3.Anyadir pelicula a sala\n");
		printf("4.Configuracion\n");
		printf("5.Eliminar pelicula de sala\n");
		printf("q salir\n");
		printf("Selecciona una opcion\n");
		fflush(stdout);
		fgets(opcion,MaxLine,stdin);
		if(opcion!="q"){
			sscanf(opcion,"%i",&opc);
		}
		int cont=contadorCine(db);
		opc=2;
		if(opc==1){
			if(cont<MaxCine){
				if(insertarCine(db,cont,cines)==0){
					printf("El cine se han introducido correctamente\n");
					printf("CodCine: %i ciudad: %s precio: %i\n",cines[cont].codCine ,cines[cont].ciudad,cines[cont].precio);
				}else{
					printf("Se ha cancelado la introduccion\n");
					printf("\n");
				}
			}else{
				printf("Los cines estan llenos\n");
			}
		} else {
		if(opc==2){
			printf("a");
			int result=insertarSalaACine(db,cont,MaxSala,cines);
			if(result==1){
				printf("La sala de cine se ha introducido en el cine correctamente\n");
			}else{
				printf("No se ha insertado ninguna informacion\n");
			}
		}
		}
		}
		//if (opcion=='3'){
			//int result=
			//int cont2=cuantaSalasCine(db, );
			
		//}

			
			
		

	}

int main(void){	
	sqlite3 *db;
	sqlite3_open("CinesAPJ.db", &db);
	Cine *cines=(Cine*)malloc(MaxCine*sizeof(Cine));
	cines=listaDeCines(db,MaxCine);
	menu(db,cines);
}