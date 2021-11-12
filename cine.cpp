#include "cine.h"
#include "pelicula.h"
#include "sala.h"

Cine::Cine()
{
    this->generarDatos();
}

void Cine::generarDatos()
{
    this->cartelera = {
        Pelicula(1, "El Rey Leon", (float)117, true, "14:30"),
        Pelicula(2, "Spiderman: Lejos de Casa", (float)130, true, "16:00"),
        Pelicula(3, "Anabelle 3: Vuelve a Casa", (float)106, false, "18:20"),
        Pelicula(4, "Avengers: End Game", (float)188, false, "16:15"),
        Pelicula(5, "Toy Story 4", (float)100, false, "11:30")};

    this->salas = {Sala(1, 5, 5),
                   Sala(2, 5, 5),
                   Sala(3, 5, 5),
                   Sala(4, 5, 5),
                   Sala(5, 5, 5)};
}

void Cine::mostrarCartelera()
{
    cout << "-- CARTELERA --" << endl;
    for (int i = 0; i < this->cartelera.size(); i++)
        this->cartelera[i].mostrarInfo();
    cout << endl;
}

void Cine::mostrarSala()
{
    int peliculaId = 0;
    do
    {
        cout << "Ingrese el id de la pelicula: " << endl;
        cin >> peliculaId;
        if (peliculaId < 1 || peliculaId > this->salas.size())
            cout << "Id invalido, intente de nuevo" << endl;
    } while (peliculaId < 1 || peliculaId > this->salas.size());

    this->salas[peliculaId].mostrarInfo();
}

void Cine::comprarBoletos()
{
    int peliculaId = -1, columna = -1, numeroBoletos = 0;
    char fila = ' ', cancelar = 'n';
    vector<Boleto> carritoCompra;

    // Seleccion de la pelicula
    do
    {
        cout << "Seleccione el id de la pelicula: " << endl;
        cin >> peliculaId;
        if (peliculaId < 1 || peliculaId > this->cartelera.size())
            cout << "El id no es valido, intente de nuevo." << endl;

    } while (peliculaId < 1 || peliculaId > this->cartelera.size());

    // Numero de boletos
    do
    {
        cout << "Ingrese el numero de boletos:" << endl;
        cin >> numeroBoletos;
        if (numeroBoletos <= 0)
            cout << "Numero invalido, intente de nuevo." << endl;
    } while (numeroBoletos <= 0);

    if (numeroBoletos < this->salas[peliculaId - 1].getAsientosDisponibles())
    {
        cout << "No hay disponibilidad de asientos. Cancelando compra..." << endl;
        return;
    }

    for (int i = 1; i <= numeroBoletos; i++)
    {
        char f;
        int c;
        do
        {
            cout << "Boleto # " << i << endl;
            cout << "Ingrese el asiento: " << endl;
            cin >> f >> c;
            if (!this->salas[peliculaId - 1].estaDisponible(f, c))
                cout << "Este asiento no esta disponible, intente de nuevo" << endl;

        } while (!this->salas[peliculaId - 1].estaDisponible(f, c));

        this->salas[peliculaId - 1].ocuparAsiento(f, c);
        Boleto b = Boleto(this->cartelera[peliculaId - 1], peliculaId, f, c);
        carritoCompra.push_back(b);
    }

    cout << "RESUMEN DE LA COMPRA:" << endl;
    for (int i = 1; i <= numeroBoletos; i++)
    {
        cout << "Boleto #" << i << endl;
        carritoCompra[i].mostrarInfo();
    }
    cout << "Total: $" << numeroBoletos * this->precio_boleto << endl;
}

int Cine::activarMenuPrincipal()
{
    cout << "++ MENU PRINCIPAL ++" << endl;
    cout << "1. Mostrar Cartelera" << endl
         << "2. Mostrar Sala" << endl
         << "3. Comprar boletos" << endl
         << "4. Salir" << endl;

    int op = 0;
    do
    {
        cout << "Ingrese su opcion:" << endl;
        cin >> op;

        if (op < 1 || op > 4)
            cout << "Opcion invalida, intente de nuevo." << endl;

    } while (op < 1 || op > 4);

    return op;
}

void Cine::activarConsola()
{
    cout << "-- MI CINE --" << endl
         << endl;
    int op = -1;

    do
    {
        op = this->activarMenuPrincipal();
        switch (op)
        {
        case 1:
            this->mostrarCartelera();
            break;

        case 2:
            this->mostrarSala();
            break;

        case 3:
            this->comprarBoletos();
            break;

        default:
            break;
        }
    } while (op != 4);
}