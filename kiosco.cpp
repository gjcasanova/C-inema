#include "kiosco.h"
#include "producto.h"
#include "productoU.h"

Kiosco::Kiosco()
{
    this->generarDatos();
}

void Kiosco::generarDatos()
{
    ProductoU canguil = ProductoU(1, 'Canguil', (float)3.5);
    ProductoU nachos = ProductoU(1, 'Nachos', (float)4);
    ProductoU gaseosa = ProductoU(1, 'Gaseosa', (float)2.75);

    this->productos.push_back(canguil);
    this->productos.push_back(nachos);
    this->productos.push_back(gaseosa);
}

int Kiosco::activarMenu()
{
    int op;
    cout << "++ MENU ++" << endl
         << endl
         << "1. Mostrar Menu" << endl
         << "2. Comprar productos" << endl
         << "3. Salir" << endl
         << endl;
    do
    {
        cout << "Seleccione una opcion:" << endl;
        cin >> op;
        cout << endl;
        if (op < 1 || op > 3)
            cout << "Opcion invalida, intente de nuevo" << endl
                 << endl;
    } while (op < 1 || op > 3);
    return op;
}

void Kiosco::activarConsola()
{
    cout << "-- MI KIOSCO --" << endl
         << endl;
    int op;
    do
    {
        op = this->activarMenu();
        switch (op)
        {
        case 1:
            this->mostrarMenu();
            break;

        case 2:
            this->comprarProductos();
            break;
        case 3:
            cout << "Un placer atenderle" << endl
                 << endl;
            return;

        default:
            cout << "Ups, algo ha salido mal.";
        }
    } while (op != 3);
}

void Kiosco::comprarProductos()
{
    int op;
    char salir;
    float totalCompra;
    vector<Producto> carrito;

    do
    {
        do
        {
            cout << "Ingrese el id del producto: " << endl;
            cin >> op;
            cout << endl;
            if (op < 1 || op > this->productos.size())
                cout << "Seleccion invalida, intente de nuevo" << endl
                     << endl;
        } while (op < 1 || op > this->productos.size());

        totalCompra += this->productos[op - 1].getPrecio();
        carrito.push_back(this->productos[op - 1]);
        cout << "Producto agregado al carrito con exito" << endl;
        cout << "Presione 's' para comprar otro producto o cualquier otra tecla para salir: " << endl;
        cin >> salir;
        cout << endl;
    } while (salir == 's');

    cout << "RESUMEN DE COMPRA" << endl
         << endl;

    for (int i = 0; i < carrito.size(); i++)
    {
        carrito[i].mostrarInfo();
    }

    cout << "Total: $" << totalCompra << endl;
}

void Kiosco::mostrarMenu()
{
    cout << "-- MENU --" << endl
         << endl;
    for (int i = 0; i < productos.size(); i++)
    {
        this->productos[i].mostrarInfo();
    }
    cout << endl;
}