#include "boleto.h"

Boleto::Boleto(Pelicula pelicula, int sala, char fila, int columna)
{
    this->sala = sala;
    this->pelicula = pelicula;
    this->fila = fila;
    this->columna = columna;
}

string Boleto::generarSecuencias(int n, string s)
{
    string result = "";
    for (int i = 0; i < n; i++)
        result += s;
    return result;
}

void Boleto::mostrarInfo()
{
    int dimensionX = 80;
    string filaSala = "Sala: " + to_string(this->sala);
    string filaHora = "Hora: " + this->pelicula.getHora();
    string filaAsiento = "Asiento: " + to_string(this->fila) + to_string(this->columna);
    string filaPelicula = "Pelicula: " + this->pelicula.getTitulo();

    cout << "╔" << this->generarSecuencias(dimensionX - 2, "═") << "╗" << endl;
    cout << "║ " << filaSala << this->generarSecuencias(dimensionX - 3 - filaSala.size(), " ") << "║" << endl;
    cout << "║ " << filaHora << this->generarSecuencias(dimensionX - 3 - filaHora.size(), " ") << "║" << endl;
    cout << "║ " << filaPelicula << this->generarSecuencias(dimensionX - 3 - filaPelicula.size(), " ") << "║" << endl;
    cout << "╚" << this->generarSecuencias(dimensionX - 2, "═") << "╝" << endl;
}
