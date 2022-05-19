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
#define MaxPeli 15


void menu(sqlite3 *db,struct Cine* cines,struct Pelicula* peliculas){
	printf("Bienvenido a cines APJ\n");
	int opc=0;
	char opcion[10];
	
	while(opcion[0]!='q'){
		opc=0;
		printf("------------------------\n");
		printf("1.Anyadir cines\n");
		printf("2.Anyadir salas\n");
		printf("3.Anyadir pelicula a sala\n");
		printf("4.Configuracion\n");
		printf("5.Eliminar pelicula de sala\n");
		printf("q salir\n");
		printf("Selecciona una opcion\n");
		fflush(stdout);
		fgets(opcion,MaxLine,stdin);
		fflush(stdin);
		if(opcion[0]=='q'){
			printf("Gracias por utilizar el programa\n");
		}	
		sscanf(opcion,"%i",&opc);
		int cont=contadorCine(db);
		if(opc==1){
			if(cont<MaxCine){
				if(insertarCine(db,cont,cines,MaxSala)==0){
					printf("El cine se han introducido correctamente\n");
					printf("CodCine: %i ciudad: %s precio: %i\n",cines[cont].codCine ,cines[cont].ciudad,cines[cont].precio);
				}else{
					printf("Se ha cancelado la introduccion\n");
					printf("\n");
				}
			}else{
				printf("Los cines estan llenos\n");
			}
		}
		if(opc==2){
			int result=insertarSalaACine(db,cont,MaxSala,cines);
			if(result==1){
				printf("La sala de cine se ha introducido en el cine correctamente\n");
			}else{
				printf("No se ha insertado ninguna informacion\n");
			}
		}
		
		if (opc==3){
			int result=insertarPeliculaASala(db,cont,cines,peliculas,MaxPeli);
			if(result==1){
				printf("La pelicula se ha anyadido correctamente\n");
			}else{
				printf("No se ha insertado ninguna informacion\n");
			}		
		
		}	
		
		if (opc==4){
			int result=crearFichero(db,cont,MaxSala,cines);
			if(result==1){
				printf("El fichero se ha creado correctamente\n");
			}else{
				printf("No se ha creado ningun fichero\n");
			}
		}
					
		

		if (opc==5){
			int result=borrarPeliculaSala(db,cont,cines);
			if(result==1){
				printf("La pelicula se ha borrado correctamente\n");
			}else{
				printf("No se ha borrado informacion\n");
			}

		}
		
	}
}

	



int main(void){	
	sqlite3 *db;
	sqlite3_open("CinesAPJ.db", &db);
	struct Pelicula* peliculas=(struct Pelicula*)malloc(MaxPeli*sizeof(struct Pelicula));
	peliculas=listaDePeliculas(db,MaxPeli);
	struct Cine *cines=(struct Cine*)malloc(MaxCine*sizeof(struct Cine));
	cines=listaDeCines(db,MaxCine,MaxSala,peliculas);
	int cuentaCin=contadorCine(db);
	for(int i=0;i<cuentaCin;i++){
		cines[i].salas=listaDeSalas(db,cines[i],MaxSala);
	}
	leerBDTransmite(db,cines,MaxCine,MaxSala,peliculas);
	menu(db,cines,peliculas);
}

