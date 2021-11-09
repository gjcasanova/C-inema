#ifndef BOLETO_H
#define BOLETO_H

#include <bits/stdc++.h>
#include "sala.h"
#include "pelicula.h"

using namespace std;

class Boleto
{
private:
    int sala;
    Pelicula pelicula;
    char fila;
    int columna;

public:
    Boleto(Pelicula pelicula, char fila, int columna);
    void mostrarInfo();
};

#endif