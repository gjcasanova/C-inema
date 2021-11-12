#include "sala.h"

Sala::Sala()
{
    this->asientosDisponibles = 0;
    this->numero = -1;
    this->numFilas = 0;
    this->numColumnas = 0;
    this->asientos = vector<vector<bool>>();
    this->filas = vector<char>();
}

Sala::Sala(int numero, int numFilas, int numColumnas)
{
    this->asientosDisponibles = numFilas * numColumnas;
    this->numero = numero;
    this->numFilas = numFilas;
    this->numColumnas = numColumnas;
    this->asientos = vector<vector<bool>>(numFilas, vector<bool>(numColumnas, false));
    this->filas = vector<char>(numFilas);
    for (int i = 0; i < numFilas; i++)
        this->filas[i] = (char)(65 + i);
}

void Sala::mostrarInfo()
{
    cout << "SALA " << this->numero << endl;
    cout << "-- ASIENTOS --" << endl;
    cout << "\t";

    for (int j = 1; j <= this->numColumnas; j++)
    {
        cout << j << "\t";
    }
    cout << endl;

    for (int i = 0; i < this->numFilas; i++)
    {
        cout << this->filas[i] << "\t";
        for (int j = 0; j < this->numColumnas; j++)
        {
            cout << (this->asientos[i][j] ? "X" : "O")
                 << "\t";
        }
        cout << endl;
    }
}

void Sala::ocuparAsiento(char fila, int columna) // Indexados en 1
{
    int filaIdx = (int)fila - 65, columnaIdx = columna - 1;
    if (this->estaDisponible(fila, columna))
    {
        this->asientos[filaIdx][columnaIdx] = true;
        this->asientosDisponibles--;
        cout << "Asiento reservado exitosamente" << endl;
    }
    else
    {
        cout << "Este asiento no se encuentra disponible o no existe" << endl;
    }
}

void Sala::limpiar()
{
    this->asientosDisponibles = this->numFilas * this->numColumnas;
    for (int i = 0; i < asientos.size(); i++)
    {
        for (int j = 0; j < asientos[i].size(); j++)
        {
            this->asientos[i][j] = false;
        }
    }
}

bool Sala::estaDisponible(char fila, int columna)
{
    int filaIdx = (int)fila - 65, columnaIdx = columna - 1;
    return columnaIdx >= 0 && filaIdx >= 0 && filaIdx < this->numFilas && columnaIdx < this->numColumnas && !this->asientos[filaIdx][columnaIdx];
}

int Sala::getAsientosDisponibles()
{
    return this->asientosDisponibles;
}