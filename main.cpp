#include <iostream>
using namespace std;

// Se determinan los movimientos válidos del caballo desde cada número del teclado
int movimientosValidos[10][3] = {
    {4, 6, -1},  // Desde 0
    {6, 8, -1},  // Desde 1
    {7, 9, -1},  // Desde 2
    {4, 8, -1},  // Desde 3
    {3, 9, 0},   // Desde 4
    {-1, -1, -1},// Desde 5 (nada, 0)
    {1, 7, 0},   // Desde 6
    {2, 6, -1},  // Desde 7
    {1, 3, -1},  // Desde 8
    {2, 4, -1}   // Desde 9
};

// Se define una función para calcular el número de movimientos válidos
int calcularMovimientos(int numero, int movimientos) { // "número" es el número en el que se encuentra el caballo y "movimientos" son los movimientos restantes
    if (movimientos == 0) return 1;

    int totalMovimientos = 0;
    for (int i = 0; i < 3; i++) {

        int nextNum = movimientosValidos[numero][i];
        if (nextNum != -1) {  // Se comprueba que el siguiente número es un movimiento válido, lo que implica que sea distinto de -1
            totalMovimientos += calcularMovimientos(nextNum, movimientos - 1);
        }
    }
    return totalMovimientos;
}

int main() {
    int movimientos;
    cout << "Introduzca la cantidad de movimientos: " << endl;
    cin >> movimientos;

    int total = 0;
    for (int i = 0; i < 10; i++) {
        total += calcularMovimientos(i, movimientos);
    }
    cout << "Total de combinaciones de movimientos validos: " << total << endl;
    return 0;
}
