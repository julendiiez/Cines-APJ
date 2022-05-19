#include "operacionBD.h"
#include "sqlite3.h"
#include <stdio.h>
#include "cine.h"
#include <string.h>
#include <stdlib.h>
#include "sala.h"
#include "pelicula.h"

int insertarDatosSala(sqlite3 *db, int CodSala, int CodCine, int Filas, int Columnas)
{
	sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO Sala (CodSala, CodCine, Fila, Columna) values (?,?,?,?)";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_int(stmt, 1, CodSala);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters1\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}
	result = sqlite3_bind_int(stmt, 2, CodCine);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}
	result = sqlite3_bind_int(stmt, 3, Filas);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters3\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}
	result = sqlite3_bind_int(stmt, 4, Columnas);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters4\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error inserting new data into SALA table\n");
		return 0;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return 1;
}

int insertarDatosCine(sqlite3 *db, int CodCine, char Ciudad[], int precio)
{
	sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO Cine (CodCine, Ciudad, Precio) values (?,?,?)";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_int(stmt, 1, CodCine);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters1\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, Ciudad, strlen(Ciudad), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_int(stmt, 3, precio);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters3\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error inserting new data into Cine table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}
int insertarDatosPelicula(sqlite3 *db, int CodPelicula, char Titulo[], char Director[], char idioma[])
{
	sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO Pelicula (CodPelicula,Titulo,Director,Idioma) values (?,?,?,?)";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_int(stmt, 1, CodPelicula);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters1\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}
	result = sqlite3_bind_text(stmt, 2, Titulo, strlen(Titulo), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}
	result = sqlite3_bind_text(stmt, 3, Director, strlen(Director), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}
	result = sqlite3_bind_text(stmt, 4, idioma, strlen(idioma), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error inserting new data into Cine table\n");
		return 0;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return 1;
}

int insertarDatosCompra(sqlite3 *db, int CodCompra, char Nick[], int CodPelicula, int Cantidad, int CodSala)
{
	sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO Compra (CodCompra,Nick,CodPelicula,Cantidad,CodSala) values (?,?,?,?,?)";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_int(stmt, 1, CodCompra);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters1\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, Nick, strlen(Nick), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_int(stmt, 3, CodPelicula);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters3\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_int(stmt, 4, Cantidad);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters3\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_int(stmt, 5, CodSala);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters3\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
		result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
		{
		printf("Error inserting new data into Cine table\n");
		return result;
		}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int insertarDatosUsuario(sqlite3 * db, char Nick[], char Nombre[], char Contrasenya[], int dinero, int edad)
{
	sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO Usuario (Nick, Nombre,Contrasenya,Dinero,Edad) values (?,?,?,?,?)";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);		
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");
	result = sqlite3_bind_text(stmt, 1, Nick, strlen(Nick), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, Nombre, strlen(Nombre), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, Contrasenya, strlen(Contrasenya), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 4, dinero);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters1\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_int(stmt, 5, edad);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters3\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error inserting new data into Cine table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");
	return SQLITE_OK;
}

int insertarDatosTransmite(sqlite3 * db, int CodSala, int CodPelicula, int Horario)
{
	sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO Transmite (CodSala,CodPelicula,Horario) values (?,?,?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_int(stmt, 1, CodSala);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters1\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
		}
	result = sqlite3_bind_int(stmt, 2, CodPelicula);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}
	result = sqlite3_bind_int(stmt, 3, Horario);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters3\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error inserting new data into Cine table\n");
		return 0;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return 0;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return 1;	
}

int contadorCine(sqlite3 *db){
	sqlite3_stmt *stmt;

	char sql[] = "Select * from Cine";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int cont=0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			cont++;
		}
	} while (result == SQLITE_ROW);
	return cont;

}
int contadorSala(sqlite3 *db){
	sqlite3_stmt *stmt;

	char sql[] = "Select * from Sala";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int cont=0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			cont++;
		}
	} while (result == SQLITE_ROW);
	return cont;

}


Cine* listaDeCines(sqlite3 *db,int taman,int maxSala,struct Pelicula* peliculas) {
	sqlite3_stmt *stmt;
	char sql[] = "select CodCine,Ciudad,Precio from Cine";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	struct Cine *cines=(struct Cine*)malloc(taman*sizeof(struct Cine));
	int a=0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			cines[a].codCine = sqlite3_column_int(stmt, 0);
			int tamanyoCiudad=strlen( (char *) sqlite3_column_text(stmt, 1));
			cines[a].ciudad=(char*)malloc((tamanyoCiudad+1)*sizeof(char));
			cines[a].ciudad=strcpy(cines[a].ciudad, (char *) sqlite3_column_text(stmt, 1));
			cines[a].ciudad[tamanyoCiudad]='\0';
			cines[a].precio=sqlite3_column_int(stmt, 2);
			cines[a].salas=(Sala*)malloc(maxSala*sizeof(Sala));
			a++;

		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		
	}

	return cines;
}

int cuentaSalasCine(sqlite3 *db, int codCine){
	sqlite3_stmt *stmt;

	char sql[] = "Select * from Sala";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int cont=0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			if(sqlite3_column_int(stmt, 1)==codCine){
			cont++;
		}
		}
	} while (result == SQLITE_ROW);
	return cont;

}

int cuantasPeliculas (sqlite3 *db){

	sqlite3_stmt *stmt;

	char sql[] = "Select * from Pelicula";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int cont=0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			cont++;
		}
	} while (result == SQLITE_ROW);
	return cont;

}


struct Sala* listaDeSalas(sqlite3 *db,struct Cine cines,int taman){
	sqlite3_stmt *stmt;

	char sql[] = "Select CodSala,CodCine,Fila,Columna from Sala";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	Sala* salas=(Sala*)malloc(taman*sizeof(Sala));
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	int a=0;
	do{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			int codcine=sqlite3_column_int(stmt, 1);

				if(codcine==cines.codCine){

					salas[a].codcine=codcine;
					salas[a].codSala=sqlite3_column_int(stmt, 0);
					salas[a].fila=sqlite3_column_int(stmt, 2);
					salas[a].columna=sqlite3_column_int(stmt, 3);
					salas[a].dimension=(int**)malloc((salas[a].columna)*sizeof(int*));

					for(int j=0;j<salas[a].columna;j++){
					
						salas[a].dimension[j]=(int*)malloc((salas[a].fila)*sizeof(int));

					}


					for(int j=0;j<salas[a].columna;j++){
						for(int k=0;k<salas[a].fila;k++){
							
							salas[a].dimension[j][k]=0;
						}

					}

					salas[a].pelis=(Pelicula*)malloc(4*sizeof(Pelicula));
					for(int k=0;k<4;k++){
						salas[a].pelis[k].horaComienzo=0;
					}
					a++;
					
				}			
			

			}
		
	}while(result == SQLITE_ROW);
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		
	}
	return salas;
}





struct Pelicula* listaDePeliculas(sqlite3 *db,int taman){
	sqlite3_stmt *stmt;

	char sql[] = "select CodPelicula,Titulo,Director,Idioma from Pelicula";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	struct Pelicula *pelicula=(struct Pelicula*)malloc(taman*sizeof(struct Pelicula));
	int a=0;
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			int codPeli=sqlite3_column_int(stmt, 0);
			pelicula[a].codPelicula=codPeli;
			char* titulo1=(char*)sqlite3_column_text(stmt, 1);
			char* director1=(char*)sqlite3_column_text(stmt, 2);
			char* idioma1=(char*)sqlite3_column_text(stmt, 3);
			int tamanyoTitulo=strlen(titulo1);
			pelicula[a].Titulo=(char*)malloc((tamanyoTitulo+1)*sizeof(char));
			pelicula[a].Titulo=strcpy(pelicula[a].Titulo,titulo1);
			pelicula[a].Titulo[tamanyoTitulo]='\0';
			int tamanyoDirector=strlen(director1);
			pelicula[a].Director=(char*)malloc((tamanyoDirector+1)*sizeof(char));
			pelicula[a].Director=strcpy(pelicula[a].Director,director1);
			pelicula[a].Director[tamanyoDirector]='\0';
			pelicula[a].horaComienzo=0;
			int tamanyoIdioma=strlen(idioma1);
			pelicula[a].idioma=(char*)malloc((tamanyoIdioma+1)*sizeof(char));
			pelicula[a].idioma=strcpy(pelicula[a].idioma,idioma1);
			pelicula[a].idioma[tamanyoIdioma]='\0';
			a++;

		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		
	}


	return pelicula;
}


void leerBDTransmite(sqlite3 *db,struct Cine *cines,int taman,int MaxSala,struct Pelicula *peliculas){
	sqlite3_stmt *stmt;
	char sql[] = "select CodSala,CodPelicula,Horario from Transmite";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	char* director1;
	char* titulo1;
	char* idioma1;
	int tamanD;
	int tamanT;
	int tamanI;
	int cantPeli=cuantasPeliculas(db);
	do{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			int codSala=sqlite3_column_int(stmt, 0);
			int codPelicula=sqlite3_column_int(stmt, 1);
			int hora=sqlite3_column_int(stmt, 2);
			for(int i=0;i<cantPeli;i++){
				if(codPelicula==peliculas[i].codPelicula){
					tamanD=strlen(peliculas[i].Director);
					director1=(char*)malloc((tamanD+1)*sizeof(char));
					director1=strcpy(director1,peliculas[i].Director);
					director1[tamanD]='\0';
					tamanT=strlen(peliculas[i].Titulo);
					titulo1=(char*)malloc((tamanT+1)*sizeof(char));
					titulo1=strcpy(titulo1,peliculas[i].Titulo);
					titulo1[tamanT]='\0';
					tamanI=strlen(peliculas[i].idioma);
					idioma1=(char*)malloc((tamanI+1)*sizeof(char));
					idioma1=strcpy(idioma1,peliculas[i].idioma);
					idioma1[tamanI]='\0';
					
				}

			}
			for(int i=0;i<taman;i++){
				int contSalCine=cuentaSalasCine(db,cines[i].codCine);
				for(int j=0;j<contSalCine;j++){
					if(cines[i].salas[j].codSala==codSala){
						if(hora==16){
							cines[i].salas[j].pelis[0].codPelicula=codPelicula;
							cines[i].salas[j].pelis[0].Director=(char*)malloc((tamanD+1)*sizeof(char));
							cines[i].salas[j].pelis[0].Director=strcpy(cines[i].salas[j].pelis[0].Director,director1);
							cines[i].salas[j].pelis[0].Director[tamanD]='\0';
							cines[i].salas[j].pelis[0].Titulo=(char*)malloc((tamanT+1)*sizeof(char));
							cines[i].salas[j].pelis[0].Titulo=strcpy(cines[i].salas[j].pelis[0].Titulo,titulo1);
							cines[i].salas[j].pelis[0].Titulo[tamanT]='\0';
							cines[i].salas[j].pelis[0].horaComienzo=16;
							cines[i].salas[j].pelis[0].idioma=(char*)malloc((tamanI+1)*sizeof(char));
							cines[i].salas[j].pelis[0].idioma=strcpy(cines[i].salas[j].pelis[0].idioma,peliculas[i].idioma);
							cines[i].salas[j].pelis[0].idioma[tamanI]='\0';
					
						}
						if(hora==18){
							cines[i].salas[j].pelis[1].codPelicula=codPelicula;
							cines[i].salas[j].pelis[1].Director=(char*)malloc((tamanD+1)*sizeof(char));
							cines[i].salas[j].pelis[1].Director=strcpy(cines[i].salas[j].pelis[0].Director,director1);
							cines[i].salas[j].pelis[1].Director[tamanD]='\0';
							cines[i].salas[j].pelis[1].Director=director1;
							cines[i].salas[j].pelis[1].Titulo=(char*)malloc((tamanT+1)*sizeof(char));
							cines[i].salas[j].pelis[1].Titulo=strcpy(cines[i].salas[j].pelis[0].Titulo,titulo1);
							cines[i].salas[j].pelis[1].Titulo[tamanT]='\0';
							cines[i].salas[j].pelis[1].horaComienzo=18;
							cines[i].salas[j].pelis[1].idioma=(char*)malloc((tamanI+1)*sizeof(char));
							cines[i].salas[j].pelis[1].idioma=strcpy(idioma1,peliculas[i].idioma);
							cines[i].salas[j].pelis[1].idioma[tamanI]='\0';

						}
						if(hora==20){
							cines[i].salas[j].pelis[2].codPelicula=codPelicula;
							cines[i].salas[j].pelis[2].Director=(char*)malloc((tamanD+1)*sizeof(char));
							cines[i].salas[j].pelis[2].Director=strcpy(cines[i].salas[j].pelis[0].Director,director1);
							cines[i].salas[j].pelis[2].Director[tamanD]='\0';
							cines[i].salas[j].pelis[2].Director=director1;
							cines[i].salas[j].pelis[2].Titulo=(char*)malloc((tamanT+1)*sizeof(char));
							cines[i].salas[j].pelis[2].Titulo=strcpy(cines[i].salas[j].pelis[0].Titulo,titulo1);
							cines[i].salas[j].pelis[2].Titulo[tamanT]='\0';
							cines[i].salas[j].pelis[2].horaComienzo=20;
							cines[i].salas[j].pelis[2].idioma=(char*)malloc((tamanI+1)*sizeof(char));
							cines[i].salas[j].pelis[2].idioma=strcpy(idioma1,peliculas[i].idioma);
							cines[i].salas[j].pelis[2].idioma[tamanI]='\0';
						}
						if(hora=22){
							cines[i].salas[j].pelis[3].codPelicula=codPelicula;
							cines[i].salas[j].pelis[3].Director=(char*)malloc((tamanD+1)*sizeof(char));
							cines[i].salas[j].pelis[3].Director=strcpy(cines[i].salas[j].pelis[0].Director,director1);
							cines[i].salas[j].pelis[3].Director[tamanD]='\0';
							cines[i].salas[j].pelis[3].Director=director1;
							cines[i].salas[j].pelis[3].Titulo=(char*)malloc((tamanT+1)*sizeof(char));
							cines[i].salas[j].pelis[3].Titulo=strcpy(cines[i].salas[j].pelis[0].Titulo,titulo1);
							cines[i].salas[j].pelis[3].Titulo[tamanT]='\0';
							cines[i].salas[j].pelis[3].horaComienzo=22;
							cines[i].salas[j].pelis[3].idioma=(char*)malloc((tamanI+1)*sizeof(char));
							cines[i].salas[j].pelis[3].idioma=strcpy(idioma1,peliculas[i].idioma);
							cines[i].salas[j].pelis[3].idioma[tamanI]='\0';
						}
							
						}
					}
						
				}
				
			}
	
	}while(result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		
	}


}
	



int borrarPeliculaDeSala(sqlite3 *db,int codSala,int codPelicula,int hora){
	sqlite3_stmt *stmt;


	char sql[] = "DELETE from Transmite where CodSala =? and CodPelicula=? and Horario=?";	

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (Delete)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	result = sqlite3_bind_int(stmt, 0, codSala);
	result = sqlite3_bind_int(stmt, 1, codPelicula);
	result=sqlite3_bind_int(stmt, 2, hora);
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error deleting data into SALA table\n");
		return 0;
	}

 	
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		
	}
	printf("Prepared statement finalized (DELETE)\n");

	return 1;


}