#include "operacionBD.h"
#include "sqlite3.h"
#include <iostream>
#include "cine.h"
#include <cstring>
#include "sala.h"
#include "pelicula.h"
#include "usuario.h"
using namespace std;

int insertarDatosSala1(sqlite3 *db, int CodSala, int CodCine, int Filas, int Columnas)
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

int insertarDatosCine1(sqlite3 *db, int CodCine, char Ciudad[], int precio)
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
int insertarDatosPelicula1(sqlite3 *db, int CodPelicula, char Titulo[], char Director[], char idioma[])
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

int insertarDatosCompra1(sqlite3 *db, int CodCompra, char Nick[], int CodPelicula, int Cantidad, int CodSala)
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

int insertarDatosUsuario1(sqlite3 * db, char Nick[], char Nombre[], char Contrasenya[], int dinero, int edad)
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

int insertarDatosTransmite1(sqlite3 * db, int CodSala, int CodPelicula, int Horario)
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

int contadorCine1(sqlite3 *db){
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
int contadorUsuario1(sqlite3 *db){
	sqlite3_stmt *stmt;

	char sql[] = "Select * from Usuario";
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
int contadorSala1(sqlite3 *db){
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


Cine* listaDeCines1(sqlite3 *db,int taman,int maxSala, Pelicula* peliculas) {
	sqlite3_stmt *stmt;
	char sql[] = "select CodCine,Ciudad,Precio from Cine";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	Cine *cines=new Cine[taman];
	int a=0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			cines[a].setCodCine(sqlite3_column_int(stmt, 0));
			cines[a].setCiudad( (char *) sqlite3_column_text(stmt, 1));
			cines[a].setPrecio(sqlite3_column_int(stmt, 2));
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

int cuentaSalasCine1(sqlite3 *db, int codCine){
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

int cuantasPeliculas1(sqlite3 *db){

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


struct Sala* listaDeSalas1(sqlite3 *db,Cine &cines,int taman){
	sqlite3_stmt *stmt;
	char sql[] = "Select CodSala,CodCine,Fila,Columna from Sala";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	Sala* salas=new Sala[taman];

	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	int a=0;
	do{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			int codcine=sqlite3_column_int(stmt, 1);
			int codSala=sqlite3_column_int(stmt, 0);
				if(codcine==cines.getCodCine()){
					salas[a].setCodCine(codcine);
					salas[a].setCodSala(codSala);
					salas[a].setFila(sqlite3_column_int(stmt, 2));
					salas[a].setColumna(sqlite3_column_int(stmt, 3));
                    Pelicula *p=new Pelicula[4];
					salas[a].setPelis(p);
					for(int k=0;k<4;k++){
						salas[a].getPelis()[k].setHoraComienzo(0);
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





Pelicula* listaDePeliculas1(sqlite3 *db,int taman){
	sqlite3_stmt *stmt;

	char sql[] = "select CodPelicula,Titulo,Director,Idioma from Pelicula";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	Pelicula *pelicula=new Pelicula[taman];
	int a=0;
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			int codPeli=sqlite3_column_int(stmt, 0);
			pelicula[a].setCodPelicula(codPeli);
			pelicula[a].setTitulo((char*)sqlite3_column_text(stmt, 1));
			pelicula[a].setDirector((char*)sqlite3_column_text(stmt, 2));
			pelicula[a].setIdioma((char*)sqlite3_column_text(stmt, 3));
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


void leerBDTransmite1(sqlite3 *db,Cine *cines,int taman,Pelicula *peliculas){
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
	int cantPeli=cuantasPeliculas1(db);
	do{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			int codSala=sqlite3_column_int(stmt, 0);
			int codPelicula=sqlite3_column_int(stmt, 1);
			int hora=sqlite3_column_int(stmt, 2);
			for(int i=0;i<cantPeli;i++){
				if(codPelicula==peliculas[i].getCodPelicula()){
					tamanD=strlen(peliculas[i].getDirector());
					director1=new char[tamanD+1];
					director1=strcpy(director1,peliculas[i].getDirector());
					tamanT=strlen(peliculas[i].getTitulo());
					titulo1=new char[tamanT+1];
					titulo1=strcpy(titulo1,peliculas[i].getTitulo());
					tamanI=strlen(peliculas[i].getIdioma());
					idioma1=new char[tamanI+1];
					idioma1=strcpy(idioma1,peliculas[i].getIdioma());
					
				}

			}
			for(int i=0;i<taman;i++){
				int contSalCine=cuentaSalasCine1(db,cines[i].getCodCine());
				for(int j=0;j<contSalCine;j++){
					if(cines[i].getSalas()[j].getCodSala()==codSala){
						if(hora==16){
							cines[i].getSalas()[j].getPelis()[0].setCodPelicula(codPelicula);
							cines[i].getSalas()[j].getPelis()[0].setDirector(director1);
							cines[i].getSalas()[j].getPelis()[0].setTitulo(titulo1);
							cines[i].getSalas()[j].getPelis()[0].setHoraComienzo(16);
							cines[i].getSalas()[j].getPelis()[0].setIdioma(idioma1);
					
						}
						if(hora==18){
							cines[i].getSalas()[j].getPelis()[1].setCodPelicula(codPelicula);
							cines[i].getSalas()[j].getPelis()[1].setDirector(director1);
							cines[i].getSalas()[j].getPelis()[1].setTitulo(titulo1);
							cines[i].getSalas()[j].getPelis()[1].setHoraComienzo(18);
							cines[i].getSalas()[j].getPelis()[1].setIdioma(idioma1);
						
						}
						if(hora==20){
							cines[i].getSalas()[j].getPelis()[2].setCodPelicula(codPelicula);
							cines[i].getSalas()[j].getPelis()[2].setDirector(director1);
							cines[i].getSalas()[j].getPelis()[2].setTitulo(titulo1);
							cines[i].getSalas()[j].getPelis()[2].setHoraComienzo(20);
							cines[i].getSalas()[j].getPelis()[2].setIdioma(idioma1);
						
						}
						if(hora==22){
							cines[i].getSalas()[j].getPelis()[3].setCodPelicula(codPelicula);
							cines[i].getSalas()[j].getPelis()[3].setDirector(director1);
							cines[i].getSalas()[j].getPelis()[3].setTitulo(titulo1);
							cines[i].getSalas()[j].getPelis()[3].setHoraComienzo(22);
							cines[i].getSalas()[j].getPelis()[3].setIdioma(idioma1);
						
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
Usuario* listaDeUsu1(sqlite3 *db,int taman){
	sqlite3_stmt *stmt;
	char sql[] = "select Nick,Nombre,Contrasenya,Dinero,Edad from Usuario";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
	Usuario *usuarios=new Usuario[taman];
	int a=0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			usuarios[a].setNick( (char *) sqlite3_column_text(stmt, 0));
			usuarios[a].setNombre( (char *) sqlite3_column_text(stmt, 1));
            usuarios[a].setContrasenya( (char *) sqlite3_column_text(stmt, 2));
			usuarios[a].setDinero(sqlite3_column_int(stmt, 3));
            usuarios[a].setEdad(sqlite3_column_int(stmt, 4));
			a++;

		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		
	}

	return usuarios;
}


	



int borrarPeliculaDeSala1(sqlite3 *db,int codSala,int codPelicula,int hora){
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
