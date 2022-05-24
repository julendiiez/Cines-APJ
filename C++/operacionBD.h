#ifndef OPERACIONBD_H
#define OPERACIONBD_H
#include "sqlite3.h"
#include "cine.h"
#include "sala.h"
#include "pelicula.h"
#include "usuario.h"

int insertarDatosSala1(sqlite3 *db,int CodSala, int CodCine, int Filas, int Columnas);
int insertarDatosPelicula1(sqlite3 *db,int CodPelicula,char Titulo[],char Director[],char idioma[]);
int insertarDatosCine1(sqlite3 *db,int CodCine,char Ciudad[],int precio);
int insertarDatosCompra1(sqlite3 *db,int CodCompra,char Nick[],int CodPelicula,int Cantidad,int CodSala);
int insertarDatosUsuario1(sqlite3 *db,char Nick[],char Nombre[],char Contrasenya[],int dinero,int edad);
int insertarDatosTransmite1(sqlite3 *db,int CodSala,int CodPelicula,int Horario);
int borrarPeliculaDeSala1(sqlite3 *db,int codSala,int codPelicula,int hora);

int contadorCine1(sqlite3 *db);
int contadorSala1(sqlite3 *db);
int cuantasPeliculas1(sqlite3 *db);
int cuentaSalasCine1(sqlite3 *db, int codCine);
int contadorUsuario1(sqlite3 *db);

Usuario* listaDeUsu1(sqlite3 *db,int taman);
Cine* listaDeCines1(sqlite3 *db,int taman,int maxSala,Pelicula *peliculas);
Sala* listaDeSalas1(sqlite3 *db,Cine &cines,int taman);
Pelicula* listaDePeliculas1(sqlite3 *db,int taman);
void leerBDTransmite1(sqlite3 *db,Cine *cines,int taman,Pelicula* peliculas);



#endif

