#ifndef KIOSCO_H
#define KIOSCO_H

#include <vector>
#include <string>
#include <iostream>
#include "producto.h"

class Kiosco
{
private:
    vector<Producto> productos;
    void generarDatos();

public:
    Kiosco();
    int activarMenu();
    void activarConsola();
    void comprarProductos();
    void mostrarMenu();
};

#endif