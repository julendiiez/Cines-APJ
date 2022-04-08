#include "sqlite3.h"
#include <stdio.h>
#include "cine.h"

#include "operacionBD.h"
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
	char sql[] = "INSERT INTO Pelicula (CodPelicula,Titulo,Director,Idioma) values (?,?,?,?,?)";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_int(stmt, 1, CodPelicula);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters1\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, Titulo, strlen(Titulo), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, Director, strlen(Director), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, idioma, strlen(idioma), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
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
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_int(stmt, 1, CodSala);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters1\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
		}
	result = sqlite3_bind_int(stmt, 2, CodPelicula);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_int(stmt, 3, Horario);
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


Cine* listaDeCines(sqlite3 *db,int taman) {
	sqlite3_stmt *stmt;

	char sql[] = "select CodCine,Ciudad,Precio from Cine";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	Cine *cines=(Cine*)malloc(taman*sizeof(Cine));
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
			a++;

		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		
	}

	printf("Prepared statement finalized (SELECT)\n");

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


Sala* listaDeSalas(sqlite3 *db,int taman) {
	sqlite3_stmt *stmt;

	char sql[] = "select CodSala,CodCine,Fila, Columna from Sala";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
		int a=0;
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			sala[a].codSala=sqlite3_column_int(stmt, 0);
			sala[a].codcine=sqlite3_column_int(stmt, 1);
			sala[a].fila=sqlite3_column_int(stmt, 2);
			sala[a].columna=sqlite3_column_int(stmt, 3);
			sala[a].dimension=(int**)malloc((sala[a].columna)*sizeof(int*));
			for(int i=0;i<sala[a].columna;i++){
				sala[a].dimension[sal[a].columna]=(int*)malloc((sala[a])*sizeof(int));
			}
			for(int i=0;i<sala[a].columna;i++){
				for(int j=0;j<sala[a].ffila;j++){
					sala[a].dimension[i][j]=0;
				}
			}			
			a++;

		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		
	}

	printf("Prepared statement finalized (SELECT)\n");

	return sala;
}


Pelicula* listaDePeliculas(sqlite3 *db,int taman){
	sqlite3_stmt *stmt;

	char sql[] = "select CodPelicula,Titulo,Director,Idioma from Pelicula";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	Pelicula *pelicula=(Pelicula*)malloc(taman*sizeof(Pelicula));
	int a=0;
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			pelicula[a].codPelicula=sqlite3_column_int(stmt, 0);
			int tamanyoTitulo=strlen( (char *) sqlite3_column_text(stmt, 1));
			pelicula[a].Titulo=strlen((char*))tamanyoCiudad+1)*sizeof(char));
			pelicula[a].Titulo=strcpy(pelicula[a].Titulo,(char*))sqlite3_column_text(stmt, 1));
			pelicula[a].Titulo[tamanyoTitulo]='\0';
			int tamanyoDirector=strlen( (char *) sqlite3_column_text(stmt, 2));
			pelicula[a].Director=strlen((char*))tamanyoDirector+1)*sizeof(char));
			pelicula[a].Director=strcpy(pelicula[a].Director,(char*))sqlite3_column_text(stmt, 2));
			pelicula[a].Director[tamanyoDirector]='\0';
			pelicula[a].horaComienzo="NULL";
			int tamanyoIdioma=strlen( (char *) sqlite3_column_text(stmt, 4));
			pelicula[a].idioma=strlen((char*))tamanyoIdioma+1)*sizeof(char));
			pelicula[a].idioma=strcpy(pelicula[a].idioma,(char*))sqlite3_column_text(stmt, 4));
			pelicula[a].idioma[tamanyoIdioma]='\0';
			a++;

		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		
	}

	printf("Prepared statement finalized (SELECT)\n");

	return pelicula;
}


void leerBDTransmite(sqlite3 *db,Sala *salas,Pelicula *peliculas){
	//si esta el codsala anyadir a ese cod sala la pelicula-- NO ENTIENDO ESO que quiere decir si esta el codsala
	//y en sala->peliculas[i].horaComienzo=horario;
	//hacemos leer por fila de bd y hacemos un for de sala, si el codsala=codsala añadimo en el array de peliculas que tiene la sala la pelicula y a esa pelicula anyadimos la hora
	//me estoy liando
	//igual lo mejor es crear otro clase transmite y realizar las funciones desde alli sin tener que relacionar varias cosas
	//y si pa simplicar una pelicula solo se echa en un horario? así no hay transmite no=?
	//transmite debe de hhaaber para relacionar salas y peli
	//creo que funciona como las primeras dos filas. porque al hacer un for de peliculas no se van a repetir porque lo hacemos desde la bd pelicula
	//
}

