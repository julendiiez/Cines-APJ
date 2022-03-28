#include "OPERACIONBD.h"
#include <stdio.h>
#include "sqlite3.h"

void insertarDatosSala(sqlite3 *db, int CodSala, int CodCine, int Filas, int Columnas ){
  	sqlite3_stmt *stmt;

	char sql[] = "insert into SALA (CodSala, CodCine, Filas, Columnas) values (?,?,?,?)";
    
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, name, strlen(name), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}
    
}


void actualizardatos();
    


void insertarDatosCine();
void actualizardatos();
    


void insertarDatosCine();
void actualizardatos();
    


void insertarDatosCine();
void insertarDatosCine();
void insertarDatosPelicula();
void eliminarPeliculaSala(){

}
