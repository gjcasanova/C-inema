#ifndef PRODUCTOU_H
#define PRODUCTOU_H

#include <vector>
#include <string>
#include <iostream>
#include "producto.h"

class ProductoU : public Producto
{
public:
    ProductoU(int id, string nombre, float precio);
};

#endif