#include "productoC.h"

ProductoC::ProductoC(int id, string nombre, float precio, vector<Producto *> subproductos) : Producto(id, nombre, precio)
{
    this->subproductos = subproductos;
}

void ProductoC::mostrarInfo()
{
    ProductoC::Producto::mostrarInfo();
    cout << "Contiene:" << endl;
    for (int i = 0; i < this->subproductos.size(); i++)
    {
        cout << "\t" << this->subproductos[i]->getNombre() << endl;
    }
}