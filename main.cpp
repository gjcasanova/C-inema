#include <bits/stdc++.h>
#include "cine.h"
#include "sala.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Cine cine = Cine();
    Sala salaPrueba = Sala(1, 5, 5);
    salaPrueba.mostrarInfo();
    salaPrueba.ocuparAsiento('A', 5);
    salaPrueba.ocuparAsiento('B', 5);
    salaPrueba.ocuparAsiento('C', 0);
    salaPrueba.ocuparAsiento('D', 1);
    salaPrueba.ocuparAsiento('A', 5);
    salaPrueba.mostrarInfo();
    salaPrueba.limpiar();
    salaPrueba.mostrarInfo();
    return 0;
}
