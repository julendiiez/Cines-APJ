#ifndef OPERACIONBD_H
#define OPERACIONBD_H
#include "sqlite3.h"
#include "cine.h"
#include "sala.h"
#include "pelicula.h"

int insertarDatosSala(sqlite3 *db,int CodSala, int CodCine, int Filas, int Columnas);
int insertarDatosPelicula(sqlite3 *db,int CodPelicula,char Titulo[],char Director[],char idioma[]);
int insertarDatosCine(sqlite3 *db,int CodCine,char Ciudad[],int precio);
int insertarDatosCompra(sqlite3 *db,int CodCompra,char Nick[],int CodPelicula,int Cantidad,int CodSala);
int insertarDatosUsuario(sqlite3 *db,char Nick[],char Nombre[],char Contrasenya[],int dinero,int edad);
int insertarDatosTransmite(sqlite3 *db,int CodSala,int CodPelicula,int Horario);
int borrarPeliculaDeSala(sqlite3 *db,int codSala,int codPelicula,int hora);

int contadorCine(sqlite3 *db);
int contadorSala(sqlite3 *db);
int cuantasPeliculas (sqlite3 *db);
int cuentaSalasCine(sqlite3 *db, int codCine);

struct Cine* listaDeCines(sqlite3 *db,int taman,int maxSala,struct Pelicula *peliculas);
void listaDeSalas(sqlite3 *db,struct Cine* cines,int taman);
struct Pelicula* listaDePeliculas(sqlite3 *db,int taman);
void leerBDTransmite(sqlite3 *db,struct Cine *cines,int taman,int MaxSala,struct Pelicula* peliculas);


#endif
