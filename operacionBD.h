#ifndef _OPERACIONBD_H
#define _OPERACIONBD_H
#include "sqlite3.h"
#include "cine.h"
#include "sala.h"

int insertarDatosSala(sqlite3 *db,int CodSala, int CodCine, int Filas, int Columnas);
int insertarDatosPelicula(sqlite3 *db,int CodPelicula,char Titulo[],char Director[],int duracion,char idioma[]);
int insertarDatosCine(sqlite3 *db,int CodCine,char Ciudad[],int precio);
int insertarDatosCompra(sqlite3 *db,int CodCompra,char Nick[],int CodPelicula,int Cantidad,int CodSala);
int insertarDatosUsuario(sqlite3 *db,char Nick[],char Nombre[],char Contrasenya[],int dinero,int edad);
int insertarDatosTransmite(sqlite3 *db,int CodSala,int CodPelicula,int Horario);
Cine *listaDeCines(sqlite3 *db,int taman);
int contadorCine(sqlite3 *db);
int cuentaSalasCine(sqlite3 *db, int codCine);
int contadorSala(sqlite3 *db);
Sala* listaDeSalas(sqlite3 *db,int taman);

#endif
