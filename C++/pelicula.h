#ifndef PELICULA_H
#define PELICULA_H



class Pelicula{
private:
    int codPelicula;
    char* titulo;
    char* director;
    int horaComienzo;
    char* idioma;
public:
    Pelicula();
    Pelicula(int codPelicula,char* titulo,char* director,int horaComienzo,char* idioma);
    ~Pelicula();
    Pelicula(const Pelicula& p);
    int getCodPelicula() const;
    char* getTitulo() const;
    char* getDirector() const;
    int getHoraComienzo() const;
    char* getIdioma() const;
    void setCodPelicula(int codPelicula);
    void setTitulo(char* titulo);
    void setDirector(char* director);
    void setHoraComienzo(int horaComienzo);
    void setIdioma(char* idioma);
    Pelicula& operator=(const Pelicula &p);
    

};


#endif