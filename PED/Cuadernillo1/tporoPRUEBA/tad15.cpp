#include <iostream>
#include "tporo.h"

using namespace std;

/**
 * Norma 6: operador de salida
 */
int main(void) {
    TPoro a, b(1, 2, -3), c(0, 1, 123456.78, "rojito");

    cout << a << endl; // vacio
    cout << b << endl; // sin color, volumen negativo
    cout << c << endl; // todo

    return 0;
}