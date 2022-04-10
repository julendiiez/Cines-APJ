#include <stdio.h>
#include "cine.h"
#include "sqlite3.h"
#include <stdlib.h>
#include <string.h>
#include "operacionBD.h"
#include "sala.h"
#include "pelicula.h"
#define MaxLine 30
#define MaxNum 10



void clearIfNeeded(char *str, int max_line)
{

	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
		while (getchar() != '\n');
}
int insertarCine(sqlite3 *db,int tamanyo,struct Cine *cines,int maxSala){
    struct Cine *c;
    c=(struct Cine*)malloc(sizeof(struct Cine));
    int precio;
    char opc;
    char str[MaxLine];
    printf("Insertar la ciudad: \n");
    fflush(stdout);
    fgets(str,MaxLine,stdin);
    char *ciudad_fmt=malloc((MaxLine)*sizeof(char));
    sscanf(str, "%s", ciudad_fmt);
	int taman = strlen(ciudad_fmt);
	c->ciudad = malloc((taman + 1) * sizeof(char));
	strcpy(c->ciudad, ciudad_fmt);
    c->ciudad[taman]='\0';
	free(ciudad_fmt);
	clearIfNeeded(str, MaxLine);
    printf("Inserta el precio: \n");
    fflush(stdout);
    fgets(str,MaxLine,stdin);
    sscanf(str,"%i",&precio);
    clearIfNeeded(str,MaxLine);
    c->precio=precio;
    c->codCine=tamanyo+1;
    printf("Todos los datos han sido introducidos\n");
    while(opc!='q'){
        printf("1.Confirmar\n");
        printf("2.Visualizar\n");
        printf("q.Cancelar\n");
        opc=getchar();
        fflush(stdin);
        if(opc=='1'){
            printf("%i\n",c->codCine);
            int result=insertarDatosCine(db,tamanyo+1,c->ciudad,c->precio);
            cines[tamanyo].codCine= c->codCine;
            cines[tamanyo].ciudad=(char*)malloc((taman+1)*sizeof(char));
            cines[tamanyo].ciudad=strcpy(cines[tamanyo].ciudad,c->ciudad);
            cines[tamanyo].ciudad[taman]='\0';
            cines[tamanyo].precio=c->precio;
            return result;
        }
        if(opc=='2'){
            printf("Los datos del nuevo cine: %i, %s, %ieuros\n",tamanyo+1,c->ciudad,c->precio);
        }
    }
        if(opc=='q'){
            return 1;
    }
}

int insertarSalaACine(sqlite3 *db,int tamanyoCines,int maxSala,struct Cine *cines){
    char str[MaxNum];
    int codCine=0;
    int fin=0;
    int result;
    int pos=0;
    for(int i=0;i<tamanyoCines;i++){
        printf("CodCine: %i, %s precio: %i euros\n",cines[i].codCine,cines[i].ciudad,cines[i].precio);
    }
    while(fin!=1)
    printf("Seleccione cine o q para volver\n");
    fflush(stdout);
    fgets(str,MaxNum,stdin);
    if(str[0]=='q'){
        return 0;
    }
    sscanf(str,"%i",&codCine);
    if(codCine>0 && codCine<=tamanyoCines){
       int totSalCine=cuentaSalasCine(db,codCine);
        int totSala=contadorSala(db);
        int numCine=contadorCine(db);
         if(totSalCine<maxSala && totSalCine>0){
             for(int i=0;i<numCine;i++){
                 if(cines[i].codCine==codCine){
                    cines[i].salas[totSala].codcine=codCine;
                    cines[i].salas[totSala].codSala=totSala;
                    pos=i;
                    result=insertarInforSala(db,codCine,pos,cines,MaxNum);
             }
             }
        
             if(result==1){
                 printf("Los datos se han introducido correctamente\n");
                 return 1;
             }else{
                 return 0;
             }
        
        }else{
            if(totSalCine==0){
                cines[pos].salas[totSalCine].codcine=codCine;
                cines[pos].salas[totSalCine].codSala=totSala;
                result=insertarInforSala(db,codCine,pos,cines,MaxNum);
                if(result==1){
                    printf("Los datos se han introducido correctamente");
                    return 1;
                }else{
                    return 0;
                }

            }else{
                printf("Ya ha llegado al numero maximo de salas que se puede introducir\n");

            }
        }

    }else{
        printf("El codigo de cine introducido no existe\n");
    }
     
}


int insertarPeliculaASala(sqlite3 *db,int tamanyoCines,struct Cine *cines, struct Pelicula *peliculas,int maxPeli){
    char str[MaxNum];
    int posCine=0;
    int posSala=0;
    int posPelicula=0;
    int posHorario=0;
    int hora=0;
    int fin=0;
    int fin1=0;
    int fin2=0;
    int fin3=0;
    int result;
    for(int i=0;i<tamanyoCines;i++){
        printf("CodCine: %i, %s precio: %i euros\n",cines[i].codCine,cines[i].ciudad,cines[i].precio);
    }
    while(fin!=1){
        printf("Seleccione cine o q para volver\n");
        fflush(stdout);
        fgets(str,MaxNum,stdin);
        if(str[0]=='q'){
            return 0;
        }
        sscanf(str,"%i",&posCine);
        if(posCine>0 && posCine<=tamanyoCines){
            fin=1;
        }else{
            printf("Ese codigo de cine no existe\n");
        }
    }
    int cantSala=cuentaSalasCine(db,posCine);
    while(fin1!=1){   
        printf("Salas del cine %i\n",posCine);
        printf("------------------\n");
        for(int i=0;i<cantSala;i++){
            printf("%i. Codigo de Sala: %i, filas: %i y columnas: %i\n",(i+1),cines[posCine-1].salas[i].codSala,cines[posCine-1].salas[i].fila,cines[posCine-1].salas[i].columna);
        }
        printf("Seleccione sala o q para volver: \n");
        fflush(stdout);
        fgets(str,MaxNum,stdin);
        if(str[0]=='q'){
            return 0;
        }
        sscanf(str,"%i",&posSala);
        if(posSala>0 && posSala<=cantSala){
            fin1=1;
        }else{
            printf("Ese codigo de sala no existe\n");
        }
    }
    int contPeliculas=cuantasPeliculas(db);
    while(fin2!=1){
        for(int i=0;i<contPeliculas;i++){
             printf("%i. CodPelicula: %i, %s titulo, %s director y %s idioma\n",(i+1), peliculas[i].codPelicula, peliculas[i].Titulo, peliculas[i].Director, peliculas[i].idioma);
        }
        printf("N para anyadir seleccionar una nueva pelicula\n");
        printf("Selecciona pelicula o q para volver\n");
        fflush(stdout);
        fgets(str,MaxNum,stdin);
        if(str[0]=='q'){
            return 0;
        }
        if(str[0]=='N'){
            if(maxPeli!=contPeliculas){
                int meteInfor=insertarInforPelicula(db,MaxLine,contPeliculas+1,cines,posCine-1,posSala-1,peliculas);
                return meteInfor;
            }else{
                printf("Ya se ha introducido el numero maximo de peliculas");
            }
            
        }else{
             sscanf(str,"%i",&posPelicula);
             if(posPelicula>0 && posPelicula<contPeliculas){
                 fin2=1;

             }else{
                 printf("El codigo introducido no es correcto");
             }
        }
    }
    int cont=0;
    for(int i=0;i<4;i++){
        if(cines[posCine-1].salas[posSala-1].pelis[i].horaComienzo==0){
            if(i==0){
                printf("1).16:00 \n");
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
        while(fin3=!1){
            printf("Selecciona una horario o q para volver");
            fflush(stdout);
            fgets(str,MaxNum,stdin);
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
            fin3=1;
            }else{
                printf("Ese codigo de sala no existe\n");
            }
        }
    }
    cines[posCine-1].salas[posSala-1].pelis[posHorario-1].codPelicula=peliculas[posPelicula-1].codPelicula;
    int tamanTitulo=strlen(peliculas[posPelicula-1].Titulo);
    cines[posCine-1].salas[posSala-1].pelis[posHorario-1].Titulo=(char*)malloc((tamanTitulo+1)*sizeof(char));
    cines[posCine-1].salas[posSala-1].pelis[posHorario-1].Titulo=strcpy(cines[posCine-1].salas[posSala-1].pelis[posHorario-1].Titulo,peliculas[posPelicula-1].Titulo);
    cines[posCine-1].salas[posSala-1].pelis[posHorario-1].Titulo[tamanTitulo]='\0';
    int tamanDirector=strlen(peliculas[posPelicula-1].Director);
    cines[posCine-1].salas[posSala-1].pelis[posHorario-1].Director=(char*)malloc((tamanDirector+1)*sizeof(char));
    cines[posCine-1].salas[posSala-1].pelis[posHorario-1].Director=strcpy(cines[posCine-1].salas[posSala-1].pelis[posHorario-1].Director,peliculas[posPelicula-1].Director);
    cines[posCine-1].salas[posSala-1].pelis[posHorario-1].Director[tamanDirector]='\0';
    int tamanIdioma=strlen(peliculas[posPelicula-1].idioma);
    cines[posCine-1].salas[posSala-1].pelis[posHorario-1].idioma=(char*)malloc((tamanIdioma+1)*sizeof(char));
    cines[posCine-1].salas[posSala-1].pelis[posHorario-1].idioma=strcpy(cines[posCine-1].salas[posSala-1].pelis[posHorario-1].idioma,peliculas[posPelicula-1].idioma);
    cines[posCine-1].salas[posSala-1].pelis[posHorario-1].idioma[tamanIdioma]='\0';
    cines[posCine-1].salas[posSala-1].pelis[posHorario-1].horaComienzo=hora;
    int inserTransmite=insertarDatosTransmite(db,cines[posCine-1].salas[posSala-1].codSala,cines[posCine-1].salas[posSala-1].pelis[posHorario-1].codPelicula,cines[posCine-1].salas[posSala-1].pelis[posHorario-1].horaComienzo);
    return inserTransmite;
    


}

int borrarPeliculaSala(sqlite3 *db,int tamanyoCines,struct Cine *cines){
    char str[MaxNum];
    int posCine=0;
    int posSala=0;
    int posPelicula=0;
    int posHorario=0;
    int hora=0;
    int fin=0;
    int fin1=0;
    int fin2=0;
    int result;
    for(int i=0;i<tamanyoCines;i++){
        printf("CodCine: %i, %s precio: %i euros\n",cines[i].codCine,cines[i].ciudad,cines[i].precio);
    }
    while(fin!=1){
        printf("Seleccione cine o q para volver\n");
        fflush(stdout);
        fgets(str,MaxNum,stdin);
        if(str[0]=='q'){
            return 0;
        }
        sscanf(str,"%i",&posCine);
        if(posCine>0 && posCine<=tamanyoCines){
            fin=1;
        }else{
            printf("Ese codigo de cine no existe\n");
        }
    }
    int cantSala=cuentaSalasCine(db,posCine);
    while(fin1!=1){   
        printf("Salas del cine %i\n",posCine);
        printf("------------------\n");
        for(int i=0;i<cantSala;i++){
            printf("%i. Codigo de Sala: %i, filas: %i y columnas: %i\n",(i+1),cines[posCine-1].salas[i].codSala,cines[posCine-1].salas[i].fila,cines[posCine-1].salas[i].columna);
        }
        printf("Seleccione sala o q para volver: \n");
        fflush(stdout);
        fgets(str,MaxNum,stdin);
        if(str[0]=='q'){
            return 0;
        }
        sscanf(str,"%i",&posSala);
        if(posSala>0 && posSala<=cantSala){
            fin1=1;
        }else{
            printf("Ese codigo de sala no existe\n");
        }
    }
    int cont=0;
    while(fin2!=1){
        for(int i=0;i<4;i++){
            if(cines[posCine-1].salas[posSala-1].pelis[i].horaComienzo!=0){
                printf("%i plazo de hora. El codigo de pelicula es: %i, el titulo es:%s, el director es=%s, la hora de comienzo es=%i y el idioma es =%s\n",(i+1),cines[posCine-1].salas[posSala-1].pelis[i].codPelicula,cines[posCine-1].salas[posSala-1].pelis[i].Titulo,cines[posCine-1].salas[posSala-1].pelis[i].Director, cines[posCine-1].salas[posSala-1].pelis[i].horaComienzo, cines[posCine-1].salas[posSala-1].pelis[i].idioma);
                cont++;
            
            }
        }
        if(cont==0){
            printf("No hay peliculas en la sala\n");
            return 0;
        }else{
            printf("Seleccione el numero de la pelicula que quiere eliminar o q para volver: \n");
            fflush(stdout);
            fgets(str,MaxNum,stdin);
            if(str[0]='q'){
                return 0;
            }
            sscanf(str,"%i",&posHorario);
            if(posHorario>0 && posHorario<=4){
                if(cines[posCine-1].salas[posSala-1].pelis[posHorario-1].horaComienzo!=0){
                    cines[posCine-1].salas[posSala-1].pelis[posHorario-1].horaComienzo=0;

                }else{
                   printf("Esa sala no contiene ninguna peli");
            }
            }
        }
    }


}


