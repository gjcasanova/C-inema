#ifndef CINE_H
#define CINE_H

#include <bits/stdc++.h>
#include "sala.h"
#include "pelicula.h"

using namespace std;

class Cine
{
private:
    static const float PRECIO_BOLETO = 3.15;
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