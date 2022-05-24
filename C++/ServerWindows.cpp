#undef UNICODE

#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x501

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "operacionBD.h"
#include "cine.h"
#include "sqlite3.h"
// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")
using namespace std;
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
#define MaxCine 10
#define MaxSala 5
#define MaxPelicula 15
#define MaxUsu 50


char* leerContrasenya();
   
int leerPuerto();

//descargar de la bd los arrays y al acabar empezar a mandar solicitu

int __cdecl main(void) 
{   
    
    char* contrasenya=leerContrasenya();
    char*contra=new char[strlen(contrasenya)+3];
    int puerto=leerPuerto();
    bool contraCorrecta=false;
    while(contraCorrecta==false){
        cout<<"Escribe la contrasenya para poder acceder a la BD: "<<endl;
        cout<<"q para salir: "<<endl;
        cin>>contra;
        if(strcmp(contra,contrasenya)==0){
            contraCorrecta=true;
        }
        if(contra[0]=='q'){
            return 0;
        }
    }
    sqlite3 *db;
	sqlite3_open("../CinesAPJ.db", &db);
    Pelicula *peliculas=new Pelicula[MaxPelicula];
    peliculas=listaDePeliculas1(db,MaxPelicula);
	Cine *cines=new Cine[MaxCine];
	cines=listaDeCines1(db,MaxCine,MaxSala,peliculas);
    int contaUsu=contadorUsuario1(db);
	int cuentaCin=contadorCine1(db);

	for(int i=0;i<cuentaCin;i++){
		cines[i].setSalas(listaDeSalas1(db,cines[i],MaxSala));
	}
	leerBDTransmite1(db,cines,cuentaCin,peliculas);
    Usuario *usuarios=new Usuario[MaxUsu];
    usuarios=listaDeUsu1(db,MaxUsu);


    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char *recvbuf;
    recvbuf=new char[DEFAULT_BUFLEN];
    //char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    char *sendbuf = "this is a test";

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Accept a client socket
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    Usuario usuario1;
    char* textoAEnviar=new char[15];
    bool coincide=false;
    closesocket(ListenSocket);
    // Receive until the peer shuts down the connection
    while(iResult!=0){
        while(coincide==false){
            cout<<"entra";
            //Recibe mensaje
            iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
            for(int i =0;i<iResult;i++){
                cout<<recvbuf[i];
            }
            recvbuf=new char[iResult];
            cout<<"////";
            cout<<recvbuf<<endl;
            if(strcmp(recvbuf,"q")){
                return 0;
            }         
            cout<<"esta";
            for (int i = 0; i < contaUsu; i++)
            {
                if(strcmp(recvbuf,usuarios[i].getNick())==0){
                    textoAEnviar=("Introduce tu contrasena: ");
                    sendbuf=new char[strlen(textoAEnviar)+1];
                    for(int i=0;i<strlen(textoAEnviar);i++){
                        sendbuf[i]=textoAEnviar[i];
                    } 
                    iSendResult = send( ClientSocket, sendbuf, (int)strlen(sendbuf), 0 );
                    coincide=true;
                    usuario1=usuarios[i];
                    
                    
                }                            
            }
            if(coincide==false){
                textoAEnviar=("El usuario no coincide, escribalo otra vez: ");
                sendbuf=new char[strlen(textoAEnviar)+1];
                for(int i=0;i<strlen(textoAEnviar);i++){
                    sendbuf[i]=textoAEnviar[i];
                }
                iSendResult = send( ClientSocket, sendbuf, (int)strlen(sendbuf), 0 ); 
            }                       
            
        }
        

        if (iSendResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }

        //Recibe mensaje
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        for(int i =0;i<iResult;i++){
            cout<<recvbuf[i];
        }
        cout<<endl;
            
        recvbuf=new char[iResult];

    }
  
        //Envia mensaje
        coincide=false;
        while(coincide==false){  
            if(strcmp(recvbuf,usuario1.getContrasenya())==0){
                textoAEnviar=("1.Comprar entradas\n 2.Ver entradas\n 3.Perfil\n o q para salir\n");
                sendbuf=new char[strlen(textoAEnviar)+1];
                    for(int i=0;i<strlen(textoAEnviar);i++){
                        sendbuf[i]=textoAEnviar[i];
                    }
                coincide=true;

            }else{
                textoAEnviar=("La contrasenya no coincide, escribala otra vez: ");
                sendbuf=new char[strlen(textoAEnviar)+1];
                for(int i=0;i<strlen(textoAEnviar);i++){
                    sendbuf[i]=textoAEnviar[i];
                }
                iSendResult = send( ClientSocket, sendbuf, (int)strlen(sendbuf), 0 ); 
            }                          
        }

        if (iSendResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        } 


        //Recibe mensaje
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        for(int i =0;i<iResult;i++){
            cout<<recvbuf[i];
        }
        cout<<endl;
            
        recvbuf=new char[iResult];


        //Envia el mensaje  
        if(recvbuf[0]=='q')
                return 0;
        int opcion;
        sscanf(recvbuf,"%i",opcion);
        if(opcion>0 && opcion<4){ 
            if(opcion==1){
                for (int i = 0; i <cuentaCin; i++)
                {
                //preguntar a jose como mandar los cines en el socket 
                    textoAEnviar=("");
                    sendbuf=new char[strlen(textoAEnviar)+1];
                    for(int i=0;i<strlen(textoAEnviar);i++){
                        sendbuf[i]=textoAEnviar[i];
                    }
                }                    
            }   

            if(opcion==2){
                //hacer una opcion de como hacer las entradas que tiene el socio
            }

            if(opcion==3){
                //funcion en usuario getInformacion  
                textoAEnviar=(usuario1.getInformacion());  
                sendbuf=new char[strlen(textoAEnviar)+1];
                    for(int i=0;i<strlen(textoAEnviar);i++){
                        sendbuf[i]=textoAEnviar[i];
                    }
                 iSendResult = send( ClientSocket, sendbuf, (int)strlen(sendbuf), 0 ); 
            }   
       }

       if (iSendResult == SOCKET_ERROR) {
            printf("send failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;

        }

    

    if (iResult == 0){
        printf("Connection closing...\n");
    }else{
        printf("recv failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }

    // Cierra la conexion
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}

char* leerContrasenya(){
    FILE* f;
    int num=0;
    char c;
    f=fopen("../Configuracion.txt","r");
    while((c=fgetc(f))!='\n'){
        num++;
    }
    fclose(f);
    f=fopen("../Configuracion.txt","r");
    char *contrasenya=new char[num+1];
    fread(contrasenya,sizeof(char),num,f);
    contrasenya[num]='\0';
    fclose(f);
    return contrasenya;
}
int leerPuerto(){
    FILE* f;
    int num=0;
    char c;
    int puerto=0;
    char* form;
    f=fopen("../Configuracion.txt","r");
    while((c=fgetc(f))!='\n'){
        num++;
    }
    form=new char[50];
    num=0; 
    fread(form,sizeof(char),500,f);
    int taman=strlen(form);
    form[taman-1]='\0';
    puerto=atoi(form);
    return puerto;

}