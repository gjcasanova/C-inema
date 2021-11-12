#ifndef PELICULA_H
#define PELICULA_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Pelicula
{
private:
    int id;
    string titulo;
    float duracion;
    bool estreno;
    string hora;
    bool vermounth;
    float precio;

public:
    Pelicula();
    Pelicula(int id, string titulo, float duracion, bool estreno, string hora, float precio, bool vermounth);
    string getTitulo();
    string getHora();
    void mostrarInfo();
    float getPrecio();
};

#endif