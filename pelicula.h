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
    Pelicula(int id, int titulo, float duracion, bool estreno, string hora);
    void mostrarInfo();
};

#endif