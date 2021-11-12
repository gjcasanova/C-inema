#ifndef BOLETO_H
#define BOLETO_H

#include <vector>
#include <string>
#include <iostream>
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

    string generarSecuencias(int n, string s);

public:
    Boleto(Pelicula pelicula, int sala, char fila, int columna);
    void mostrarInfo();
};

#endif