#include "pelicula.h"
#include "sqlite3.h"
#include <stdio.h>


//esta funcion es para meter datos de la nueva peli que queremos añadir al array de pelis, solo se entra a esta
//opcion si se elige la opcion de nueva peli. Sino no se utiliza esto y directamente se guarda en transmite la relacion sala peli. 
//hacer esto para las nuevas pelis. Y luego despues de esto se inserta datos en la tabla transmite 
//entonces ahora que puedo hacer ? :D
//entonces hay que hacer la funcion de abajo ahora?
//si la puedes hacer pero tienes que pasar como parametro codSala que se ha elegido para guardar en pelicula
//pero tambien guardar en transimte. Hay q meter los datos en 2 tablas.
//es un insert la funcion ya esta hecha. 
//esque lo de transmite todavía se me queda grande poco a poco ajajaja
//entonces hago lo de abajo ahora no?
//si 



int insertarInforPelicula(sqlite3 *db,int codPelicula,int codSala, int maxPelicula,Pelicula* peli,int MaxNum){
    
}
