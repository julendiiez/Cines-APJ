#include "usuario.h"

Usuario::Usuario(){
    this->nick="";
    this->nombre="";
    this->contrasenya="";
    this->dinero=0;
    this->edad;

}
Usuario::Usuario(char* nick,char* nombre,char* contrasenya,int dinero, int edad){
    this->nick=nick;
    this->nombre=nombre;
    this->contrasenya=contrasenya;
    this->dinero=dinero;
    this->edad=edad;
}
    
Usuario::~Usuario(){
    delete[] nick;
    delete[] nombre;
    delete[] contrasenya;
}

char* Usuario::getNick(){
    return nick;
}

char* Usuario::getNombre(){
    return nombre;
}

char* Usuario::getContrasenya(){
    return contrasenya;
}

int Usuario::getDinero(){
    return dinero;
}

int Usuario::getEdad(){
    return edad;
}

char* Usuario::setNick(){
    this->nick=nick;
}

char* Usuario::setNombre(){
    this->nombre=nombre;
}

char* Usuario::setContrasenya(){
    this->contrasenya=contrasenya;
}

int Usuario::setDinero(){
    this->dinero=dinero;
}

int Usuario::setEdad(){
    this->edad=edad;
}



