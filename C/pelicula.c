#include "pelicula.h"
#include "operacionBD.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int insertarInforPelicula(sqlite3 *db,int MaxLine,int codPeli, struct Cine *cines,int posCine,int posSala, Pelicula * peliculas){
    char str[MaxLine];
    int fin=0;
    int fin1=0;
    int fin2=0;
    int opcFinal=0;
    int idiomaSelec=0;
    int posHorario=0;
    int hora=0;
    char* idioma;
    printf("Introduce Titulo: \n");
    fflush(stdout);
    fgets(str,MaxLine,stdin);
    char *titulo_fmt=malloc((MaxLine)*sizeof(char));
    sscanf(str, "%s", titulo_fmt);
    printf("Introduce Director: \n");
    fflush(stdout);
    fgets(str,MaxLine,stdin);
    char *director_fmt=malloc((MaxLine)*sizeof(char));
    sscanf(str, "%s", director_fmt);
    while(fin!=1){
        printf("1.Castellano\n");
        printf("2.Euskera\n");
        printf("3.Ingles\n");
        printf("Seleccionar un idioma\n");
        fflush(stdout);
        fgets(str,MaxLine,stdin);
        sscanf(str,"%i",&idiomaSelec);
        if(idiomaSelec>0 && idiomaSelec<=3){
            if(idiomaSelec==1){
                char* idioma1="Castellano";
                int taman=strlen(idioma1);
                idioma=(char*)malloc((taman+1)*sizeof(char));
                idioma=strcpy(idioma,idioma1);
                idioma[taman]='\0';
                fin=1;
            }
            if(idiomaSelec==2){
                char* idioma1="Euskera";
                int taman=strlen(idioma1);
                idioma=(char*)malloc((taman+1)*sizeof(char));
                idioma=strcpy(idioma,idioma1);
                idioma[taman]='\0';
                fin=1;
            }
            if(idiomaSelec==3){
                char* idioma1="Ingles";
                int taman=strlen(idioma1);
                idioma=(char*)malloc((taman+1)*sizeof(char));
                idioma=strcpy(idioma,idioma1);
                idioma[taman]='\0';
                fin=1;
            } 
               
        }else{
            printf("El numero seleccionado no es correcto\n");
        } 
    }
    int cont=0;
    for(int i=0;i<4;i++){
        if(cines[posCine].salas[posSala].pelis[i].horaComienzo==0){
            if(i==0){
                printf("1). 16:00 \n");
                cont++;
            }
            if(i==1){
                printf("2). 18:00\n");
                cont++;
            }
            if(i==2){
                printf("3). 20:00\n");
                cont++;
            }
            if(i==3){
                printf("4). 22:00\n");
                cont++;
            }
        }
    }
    if(cont==0){
        printf("Todos los horarios estan llenos\n");
        printf("para almacenar en esta sala primero elimina mediante la opcion 5 del menu\n");
        return 0;
    }else{
        while(fin1!=1){
            printf("Selecciona una horario o q para volver");
            fflush(stdout);
            fgets(str,MaxLine,stdin);
            if(str[0]=='q'){
                return 0;
            }
            sscanf(str,"%i",&posHorario);
             if(posHorario>0 && posSala<=4){
                 if(posHorario==1){
                    hora=16;
                 }
                 if(posHorario==2){
                     hora=18;
                 }
                 if(posHorario==3){
                     hora=20;
                 }
                 if(posHorario==4){
                     hora=22;
                 }
            fin1=1;
            }else{
                printf("Ese codigo de sala no existe\n");
            }
        }  
    

    while(fin2!=1){
        printf("1.ConfirmarDatos\n");
        printf("2.Visualizar\n");
        printf("q.Cancelar\n");
        fflush(stdout);
        fgets(str,MaxLine,stdin);
        if(str[0]=='q'){
            return 0;
        }
        sscanf(str,"%i",&opcFinal);
        if(opcFinal>0 &&opcFinal<3){
            if(opcFinal==1){
                cines[posCine].salas[posSala].pelis[posHorario-1].codPelicula=codPeli;
                int tamanT=strlen(titulo_fmt);
                cines[posCine].salas[posSala].pelis[posHorario-1].Titulo=(char*)malloc((tamanT+1)*sizeof(char));
                cines[posCine].salas[posSala].pelis[posHorario-1].Titulo=strcpy(cines[posCine].salas[posSala].pelis[posHorario-1].Titulo,titulo_fmt);
                cines[posCine].salas[posSala].pelis[posHorario-1].Titulo[tamanT]='\0';
                int tamanD=strlen(director_fmt);
                cines[posCine].salas[posSala].pelis[posHorario-1].Director=(char*)malloc((tamanD+1)*sizeof(char));
                cines[posCine].salas[posSala].pelis[posHorario-1].Director=strcpy(cines[posCine].salas[posSala].pelis[posHorario-1].Director,director_fmt);
                cines[posCine].salas[posSala].pelis[posHorario-1].Director[tamanD]='\0';
                cines[posCine].salas[posSala].pelis[posHorario-1].horaComienzo=hora;
                int tamanI=strlen(idioma);
                cines[posCine].salas[posSala].pelis[posHorario-1].idioma=(char*)malloc((tamanI+1)*sizeof(char));
                cines[posCine].salas[posSala].pelis[posHorario-1].idioma=strcpy(cines[posCine].salas[posSala].pelis[posHorario-1].idioma,idioma);
                cines[posCine].salas[posSala].pelis[posHorario-1].idioma[tamanI]='\0';
                peliculas[codPeli-1].codPelicula=codPeli;
                peliculas[codPeli-1].Titulo=(char*)malloc((tamanT+1)*sizeof(char));
                peliculas[codPeli-1].Titulo=strcpy(peliculas[codPeli-1].Titulo,titulo_fmt);
                peliculas[codPeli-1].Titulo[tamanT]='\0';
                free(titulo_fmt);
                peliculas[codPeli-1].Director=(char*)malloc((tamanD+1)*sizeof(char));
                peliculas[codPeli-1].Director=strcpy(peliculas[codPeli-1].Director,director_fmt);
                peliculas[codPeli-1].Director[tamanD]='\0';
                free(director_fmt);
                peliculas[codPeli-1].horaComienzo=0;
                peliculas[codPeli-1].idioma=(char*)malloc((tamanI+1)*sizeof(char));
                peliculas[codPeli-1].idioma=strcpy(peliculas[codPeli-1].idioma,idioma);
                peliculas[codPeli-1].idioma[tamanI]='\0';
                int insertBDtrans=insertarDatosTransmite(db,cines[posCine].salas[posSala].codSala,codPeli,hora);
                int insertBDPeli=insertarDatosPelicula(db,codPeli,peliculas[codPeli-1].Titulo,peliculas[codPeli-1].Director,peliculas[codPeli-1].idioma);
                if(insertBDtrans==1 && insertBDPeli==1){
                    return 1;
                }else{
                    return 0;
                }

            }
            if(opcFinal==2){
                printf("Pelicula con codPelicula: %i, Titulo: %s, Director: %s, Hora de comienzo: %i, idioma: %s",codPeli,titulo_fmt,director_fmt,hora,idioma);
            }
        }

        }
    }
}
