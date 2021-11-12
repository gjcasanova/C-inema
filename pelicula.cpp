#include "pelicula.h"

Pelicula::Pelicula()
{
    this->id = -1; // -1 indica que no se le ha definido un id;
    this->precio = 0;
    this->titulo = "";
    this->vermounth = false;
    this->duracion = 0.0;
    this->estreno = false;
    this->hora = "";
}

Pelicula::Pelicula(int id, string titulo, float duracion, bool estreno, string hora, float precio, bool vermounth)
{
    this->id = id;
    this->precio = precio;
    this->titulo = titulo;
    this->duracion = duracion;
    this->estreno = estreno;
    this->vermounth = vermounth;
    this->hora = hora;
}

void Pelicula::mostrarInfo()
{
    cout << this->id << " - [" << this->hora << "] " << this->titulo << " (" << duracion << ") " << (this->estreno ? "* ESTRENO *" : "") << " " << (this->vermounth ? "* VERMOUNTH *" : "") << " [$ " << this->getPrecio() << "]" << endl;
}

string Pelicula::getTitulo()
{
    return this->titulo;
}

string Pelicula::getHora()
{
    return this->hora;
}

float Pelicula::getPrecio()
{
    if (this->vermounth) // Si la funcion es Vermouth se aplica el 25% de descuento al precio original.
        return this->precio * 0.75;
    return this->precio;
}