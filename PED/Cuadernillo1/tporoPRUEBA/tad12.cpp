#include <iostream>
#include "tporo.h"

using namespace std;

/**
 * Norma 2: TPoro puede tener volumen negativo
 */
int main(void) {
    TPoro a;

    a.Volumen(-15.0);

    if (a.Volumen() == -15.0)
        cout << "Volumen es negativo" << endl;
    cout << a << endl;
}