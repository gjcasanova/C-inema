#ifndef PELICULA_H
#define PELICULA_H

#include <bits/stdc++.h>

using namespace std;

class Pelicula
{
private:
    int id;
    string titulo;
    float duracion;
    bool estreno;
    string hora;

public:
    Pelicula();
    Pelicula(int id, string titulo, float duracion, bool estreno, string hora);
    string getTitulo();
    string getHora();
    void mostrarInfo();
};

#endif