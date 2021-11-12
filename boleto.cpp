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
    // Toma un texto s y lo repite n veces. Sirve para la impresion del boleto.
    string result = "";
    for (int i = 0; i < n; i++)
        result += s;
    return result;
}

void Boleto::mostrarInfo()
{
    int dimensionX = 80; // Es la dimension del boleto.
    string filaSala = "Sala: " + to_string(this->sala);
    string filaHora = "Hora: " + this->pelicula.getHora();
    string filaAsiento = "Asiento: " + string(1, this->fila) + to_string(this->columna);
    string filaPelicula = "Pelicula: " + this->pelicula.getTitulo();

    // Impresion del boleto.
    cout << "╔" << this->generarSecuencias(dimensionX - 2, "═") << "╗" << endl;
    cout << "║ " << filaSala << this->generarSecuencias(dimensionX - 3 - filaSala.size(), " ") << "║" << endl;
    cout << "║ " << filaHora << this->generarSecuencias(dimensionX - 3 - filaHora.size(), " ") << "║" << endl;
    cout << "║ " << filaAsiento << this->generarSecuencias(dimensionX - 3 - filaAsiento.size(), " ") << "║" << endl;
    cout << "║ " << filaPelicula << this->generarSecuencias(dimensionX - 3 - filaPelicula.size(), " ") << "║" << endl;
    cout << "╚" << this->generarSecuencias(dimensionX - 2, "═") << "╝" << endl;
}
