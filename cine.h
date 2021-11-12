#ifndef CINE_H
#define CINE_H

#include <vector>
#include <string>
#include <iostream>
#include "sala.h"
#include "pelicula.h"
#include "boleto.h"

using namespace std;

class Cine
{
private:
    vector<Sala> salas;
    vector<Pelicula> cartelera;

public:
    Cine();
    void generarDatos();
    void mostrarCartelera();
    void mostrarSala();
    void comprarBoletos();
    void activarConsola();
    int activarMenuPrincipal();
};

#endif