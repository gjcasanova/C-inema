#include "sala.h"

Sala::Sala()
{
    this->numero = -1;
    this->numFilas = 0;
    this->numColumnas = 0;
    this->asientos = vector<vector<bool>>();
    this->filas = vector<char>();
}

Sala::Sala(int numero, int numFilas, int numColumnas)
{
    this->numero = numero;
    this->numFilas = numFilas;
    this->numColumnas = numColumnas;
    this->asientos = vector<vector<bool>>(numFilas, vector<bool>(numColumnas, false));
    this->filas = vector<char>(numFilas);
    for (int i = 0; i < numFilas; i++)
        this->filas[i] = (char)(97 + i);
}

void Sala::mostrarInfo()
{
    cout << "SALA " << this->numero << endl;
    cout << "-- ASIENTOS --" << endl;
    cout << "\t";

    for (int j = 1; j <= this->numColumnas; j++)
    {
        cout << j << "\t"
    }
    cout << endl;

    for (int i = 0; i < this->numFilas; i++)
    {
        cout << this->filas[i] << "\t";
        for (int j = 0; j < this->numColumnas; j++)
        {
            cout << (this->asientos[i][j] ? "O" : "X")
                 << "\t";
        }
        cout << endl;
    }
}

void Sala::ocuparAsiento(char fila, int columna) // Indexados en 1
{
    int filaIdx = (int)fila - 97, columnaIdx = columna - 1;
    if (filaIdx < this->numFilas && columnaIdx < this->numColumnas)
    {
        if (!this->asientos[filaIdx][columnaIdx])
        {
            this->asientos[filaIdx][columnaIdx] = true;
            cout << "Asiento reservado exitosamente" << endl;
        }
        else
        {
            cout << "Este asiento ya se encuentra ocupado" << endl;
        }
    }
    else
    {
        cout << "Fila o columna fuera de rango" << endl;
    }
}

void Sala::limpiar()
{
    for (int i = 0; i < asientos.size(); i++)
    {
        for (int j = 0; j < asientos[i].size(); j++)
        {
            this->asientos = false;
        }
    }
}