#include "pelicula.h"
#include "sqlite3.h"
#include <stdio.h>
#include 


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
    char str[MaxNum];
    int fin=0;
    //int totSalCine=cuentaSalasCine(db,codCine);
    //int totSala=contadorSala(db);
    while(fin!=1){
        printf("Seleccione fila: Maximo: 15 o q para volver\n");
        fflush(stdout);
        fgets(str,MaxNum,stdin);
        if(str[0]=='q'){
            return 0;
        }
        sscanf(str,"%i",&fila);
        if(fila>0 && fila<=15){
            sala[totSala].fila=fila;
            fin=1;

        }else{
            printf("El numero de fila introducido no es correcto\n");
        }
    }
    fin=0;
    while(fin!=1){
        printf("Seleccione columna: Maximo: 20 o q para volver\n");
        fflush(stdout);
        fgets(str,MaxNum,stdin);
        if(str[0]=='q'){
            return 0;
        }
        sscanf(str,"%i",&columna);
        if(columna>0 && columna<=15){
            sala[totSala].columna=columna;
            int inbd=insertarDatosSala(db,sala[totSala].codSala,sala[totSala].codcine,sala[totSala].fila,sala[totSala].columna);
            if(inbd==1){
                printf("En la base de datos se ha introducido correctamente\n");
            }else{
                printf("Ha ocurrido un error al insertar en la base de datos\n");
            }
            fin=1;
        }else{
            printf("El numero de columna introducido no es correcto\n");
        }

    }

    sala[totSala].dimension=(int**)malloc((sala[totSala].columna)*sizeof(int*));
    for(int i=0;i<sala[totSala].columna;i++){
        sala[totSala].dimension[columna]=(int*)malloc((sala[totSala].fila)*sizeof(int));

    }
    for(int i=0;i<sala[totSala].columna;i++){
        for(int j=0;j<sala[totSala].fila;j++){
            sala[totSala].dimension[i][j]=0;

        }
    }
    return 1;
}
