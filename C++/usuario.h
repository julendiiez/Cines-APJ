#ifndef USUARIO_H
#define USUARIO_H

class Usuario{
private:
    char* nick;
    char* nombre;
    char* contrasenya;
    int dinero;
    int edad;

public:
    Usuario();
    Usuario(char* nick,char* nombre,char* contrasenya,int dinero, int edad);
    ~Usuario();
    char* getNick();
    char* getNombre(); 
    char* getContrasenya();
    int getDinero();
    int getEdad();
    char* setNick();
    char* setNombre();
    char* setContrasenya();
    int setDinero();
    int setEdad();


};

#endif