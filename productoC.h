#ifndef PRODUCTOC_H
#define PRODUCTOC_H

#include <vector>
#include <string>
#include <iostream>
#include "producto.h"

class ProductoC : public Producto
{
private:
    vector<Producto> subproductos;

public:
    ProductoC(int id, string nombre, float precio, vector<Producto> subproductos);
    void mostrarInfo();
};

#endif