#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Producto
{
protected:
    int id;
    string nombre;
    float precio;

public:
    Producto();
    Producto(int id, string nombre, float precio);
    float getPrecio();
    virtual void mostrarInfo();
    string getNombre();
};

#endif