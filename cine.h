#ifndef CINE_H
#define CINE_H

#include <bits/stdc++.h>
#include "sala.h"
#include "pelicula.h"

using namespace std;

class Cine
{
private:
    float precio_boleto;
    vector<Sala> salas;
    vector<Pelicula> peliculas;

public:
    Cine();
    void generarDatos();
    void mostrarCartelera();
    void mostrarSala(int numero);
    void comprarBoleto();
};

#endif