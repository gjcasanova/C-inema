#include "cine.h"
#include "pelicula.h"
#include "sala.h"

Cine::Cine()
{
    // Llama a la funcion generadora
    this->generarDatos();
}

void Cine::generarDatos()
{
    // Instancia y carga la cartelera y las salas.
    this->cartelera = {
        Pelicula(1, "El Rey Leon", (float)117, true, "10:30", (float)5, true),
        Pelicula(2, "Spiderman: Lejos de Casa", (float)130, true, "16:00", (float)3, false),
        Pelicula(3, "Anabelle 3: Vuelve a Casa", (float)106, false, "18:20", (float)3.5, false),
        Pelicula(4, "Avengers: End Game", (float)188, false, "11:15", (float)6, true),
        Pelicula(5, "Toy Story 4", (float)100, false, "11:30", (float)3.5, false)};

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
    cout << endl
         << endl;
}

void Cine::mostrarSala()
{
    // Solicita al usuario especificar la sala a mostrar y luego de validar la entrada muestra la distribucion
    // de asientos.
    int peliculaId = 0;
    do
    {
        cout << "Ingrese el id de la pelicula: " << endl;
        cin >> peliculaId;
        cout << endl;
        if (peliculaId < 1 || peliculaId > this->salas.size())
            cout << "Id invalido, intente de nuevo" << endl
                 << endl;
    } while (peliculaId < 1 || peliculaId > this->salas.size());

    this->salas[peliculaId - 1].mostrarInfo();
    cout << endl;
}

void Cine::comprarBoletos()
{
    // Abarca todo el proceso de compra de boletos.
    int peliculaId = -1, columna = -1, numeroBoletos = 0;
    char fila = ' ';
    vector<Boleto> carritoCompra;

    // Seleccion de la pelicula
    do
    {
        cout << "Seleccione el id de la pelicula: " << endl;
        cin >> peliculaId;
        cout << endl;
        if (peliculaId < 1 || peliculaId > this->cartelera.size())
            cout << "El id no es valido, intente de nuevo." << endl
                 << endl;

    } while (peliculaId < 1 || peliculaId > this->cartelera.size());

    this->cartelera[peliculaId - 1].mostrarInfo();
    this->salas[peliculaId - 1].mostrarInfo();

    // Numero de boletos
    do
    {
        cout << "Ingrese el numero de boletos:" << endl;
        cin >> numeroBoletos;
        cout << endl;
        if (numeroBoletos <= 0)
            cout << "Numero invalido, intente de nuevo." << endl
                 << endl;
    } while (numeroBoletos <= 0);


    // Valida que exista la cantidad de boletos que desea el usuario.
    if (numeroBoletos > this->salas[peliculaId - 1].getAsientosDisponibles())
    {
        cout << "No hay disponibilidad de asientos. Cancelando compra..." << endl
             << endl;
        return;
    }

    float subtotalCompra = 0; // Acumula el subtotal generado por cada boleto adquirido
    for (int i = 1; i <= numeroBoletos; i++)
    {
        char f; // Fila
        int c; // Columna
        do
        {
            cout << "Boleto # " << i << endl;
            cout << "Ingrese el asiento: " << endl;
            cin >> f >> c;
            cout << endl;
            if (!this->salas[peliculaId - 1].estaDisponible(f, c))
                cout << "Este asiento no esta disponible, intente de nuevo" << endl
                     << endl;

        } while (!this->salas[peliculaId - 1].estaDisponible(f, c));

        char descuento = 'n';
        cout << "presione 's' para aplicar un descuento de ninos y acianos en este boleto, u otro caracter para ignorar:" << endl;
        cin >> descuento;
        cout << endl;

        // Permite al operador aplicar un descuento por edad de acuerdo al extra 3.
        if (descuento == 's')
            subtotalCompra += this->cartelera[peliculaId - 1].getPrecio() * 0.5; // Descuento del 50%
        else
            subtotalCompra += this->cartelera[peliculaId - 1].getPrecio();

        // Se marca el asiento como ocupado.
        this->salas[peliculaId - 1]
            .ocuparAsiento(f, c);

        // Se crea el boleto y se agrega al carrito de compras
        Boleto b = Boleto(this->cartelera[peliculaId - 1], peliculaId, f, c);
        carritoCompra.push_back(b);
    }

    // Se muestran los boletos y los costos de la compra
    cout << "RESUMEN DE LA COMPRA:" << endl
         << endl;
    for (int i = 1; i <= numeroBoletos; i++)
    {
        cout << "Boleto #" << i << endl
             << endl;
        carritoCompra[i - 1].mostrarInfo();
        cout << endl;
    }

    // Extra 1
    cout << "Subtotal: $" << subtotalCompra << endl;
    cout << "IVA (12%): $" << subtotalCompra * 0.12 << endl;
    cout << "Total: $" << subtotalCompra * 1.12 << endl
         << endl;
}

int Cine::activarMenuPrincipal()
{
    // Muestra el menu y retorna la seleccion del usuario.
    cout << "++ MENU PRINCIPAL ++" << endl;
    cout << "1. Mostrar Cartelera" << endl
         << "2. Mostrar Sala" << endl
         << "3. Comprar boletos" << endl
         << "4. Salir" << endl
         << endl;

    int op = 0;
    do
    {
        cout << "Ingrese su opcion:" << endl;
        cin >> op;
        cout << endl;
        if (op < 1 || op > 4)
            cout << "Opcion invalida, intente de nuevo." << endl
                 << endl;

    } while (op < 1 || op > 4);

    return op;
}

void Cine::activarConsola()
{
    // Lanza la consola interactiva.
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