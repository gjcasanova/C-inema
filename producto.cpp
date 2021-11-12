#include "producto.h"

Producto::Producto()
{
    this->id = -1;
    this->nombre = "";
    this->precio = 0;
}

Producto::Producto(int id, string nombre, float precio)
{
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
}

float Producto::getPrecio()
{
    return this->precio;
}

void Producto::mostrarInfo()
{
    cout << this->id << ". " << this->nombre << " [$ " << this->precio << "]" << endl;
}
