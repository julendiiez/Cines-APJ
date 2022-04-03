#include "sqlite3.h"
#include <stdio.h>
#include "OPERACIONBD.h"
#include <string.h>
#include <stdlib.h>
#include "cine.h"

int insertarDatosSala(sqlite3 *db, int CodSala, int CodCine, int Filas, int Columnas)
{
	sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO Sala (CodSala, CodCine, Fila, Columna) values (?,?,?,?)";

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
	result = sqlite3_bind_int(stmt, 2, CodCine);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters2\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_int(stmt, 3, Filas);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters3\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_int(stmt, 4, Columnas);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters4\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error inserting new data into SALA table\n");
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
int insertarDatosPelicula(sqlite3 *db, int CodPelicula, char Titulo[], char Director[], int duracion, char idioma[])
{
	sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO Pelicula (CodPelicula,Titulo,Director,Duracion,Idioma) values (?,?,?,?,?)";

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
	result = sqlite3_bind_int(stmt, 4, duracion);
	if (result != SQLITE_OK)
	{
		printf("Error binding parameters3\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, idioma, strlen(idioma), SQLITE_STATIC);
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

	char sql[] = "select CodCine,Ciudad,Precio from Cine";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int cont=0;
	result = sqlite3_step(stmt) ;
	do {
		if (result == SQLITE_ROW) {
			cont++;
		}
	} while (result == SQLITE_ROW);
	return cont;

}


Cine* listaDeCines(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select CodCine,Ciudad,Precio from Cine";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	int precio;
	int cont=contadorCine(db);
	Cine *cines=(Cine*)malloc(cont*sizeof(Cine));
	cont=0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			cines[cont].codCine = sqlite3_column_int(stmt, 1);
			strcpy(cines[cont].ciudad, (char *) sqlite3_column_text(stmt, 2));
			cines[cont].precio=sqlite3_column_int(stmt, 3);
			printf("CodCine: %i ciudad: %s precio: %i\n",cines[cont].codCine ,cines[cont].precio);
			cont++;

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

