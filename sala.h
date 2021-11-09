#ifndef SALA_H
#define SALA_H

#include <bits/stdc++.h>

using namespace std;

class Sala
{
private:
    int numero;
    vector<vector<bool>> asientos;
    vector<char> filas;

public:
    Sala();
    Sala(int numero, int filas, int columnas);
    void mostrarInfo();
    void ocuparAsiento(char fila, int columna);
    void limpiar();
};

#endif