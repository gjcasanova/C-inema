#include "pelicula.h"

Pelicula::Pelicula()
{
    this->id = -1; // -1 indica que no se le ha definido un id;
    this->titulo = "";
    this->duracion = 0.0;
    this->estreno = false;
    this->hora = "";
}

Pelicula::Pelicula(int id, int titulo, float duracion, bool estreno, string hora)
{
    this->id = id;
    this->titulo = titulo;
    this->duracion = duracion;
    this->estreno = estreno;
    this->hora = hora;
}

void Pelicula::mostrarInfo()
{
    cout << "[" << this->hora << "] " << this->titulo << " (" << duracion << ") " << (this->estreno ? "* ESTRENO *" : "") << endl;
}

string Pelicula::getTitulo()
{
    return this->titulo;
}

string Pelicula::getHora()
{
    return this->hora;
}