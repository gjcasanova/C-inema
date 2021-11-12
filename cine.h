#ifndef CINE_H
#define CINE_H

#include <vector>
#include <string>
#include <iostream>
#include "sala.h"
#include "pelicula.h"
#include "boleto.h"
#include "kiosco.h"
#include "producto.h"
#include "productoU.h"
#include "productoC.h"
using namespace std;

class Cine
{
private:
    vector<Sala> salas;
    vector<Pelicula> cartelera;
    Kiosco kiosco;

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