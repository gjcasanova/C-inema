#ifndef SALA_H
#define SALA_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Sala
{
private:
    int numero;
    int numFilas;
    int numColumnas;
    int asientosDisponibles;
    vector<vector<bool>> asientos; //Indica la disponibilidad de los asientos.
    vector<char> filas;

public:
    Sala();
    Sala(int numero, int numFilas, int numColumnas);
    void mostrarInfo(); // Muestra la distribucion de los asientos y su disponibilidad
    void ocuparAsiento(char fila, int columna); //marca un asiento como ocupado
    void limpiar();
    bool estaDisponible(char fila, int columna); //Sirve para determinar si un asiento existe y esta disponible o no
    int getAsientosDisponibles(); // Getter
};

#endif