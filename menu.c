#include <stdio.h>

void menu(){
	printf("Bienvenido a cines APJ\n");
	char opcion;
	while(opcion!='q'){
		printf("1.Anyadir pelicula a sala\n");
		printf("2.Anyadir cines,\n");
		printf("3.Anyadir salas\n");
		printf("4.Configuracion\n");
		printf("5.Eliminar pelicula de sala\n");
		printf("r volver\n");
		printf("q salir\n");
		printf("Selecciona una opcion\n");
		scanf("%c",&opcion);
		fflush(stdin);

	}
}