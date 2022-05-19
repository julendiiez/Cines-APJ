#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

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


int main(void){
    char*contra;
    char* contrasenya=leerContrasenya();
    int puerto=leerPuerto();
    bool contraCorrecta=false;
    bool entra=true;
    while(!contraCorrecta){
        cout<<"Escribe la contrasenya para poder acceder a la BD: "<<endl;
        cout<<"q para salir: "<<endl;
        cin>>contra;
        if(contra==contrasenya){
            contraCorrecta=true;
        }
        if(contra[0]=='q'){
            return 0;
            contraCorrecta=true;
        }
    }

        //descargar de la bd los arrays y al acabar empezar a mandar solicitudes
    
    
    

}