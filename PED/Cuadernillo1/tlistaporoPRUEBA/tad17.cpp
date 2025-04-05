#include <iostream>
#include "tlistaporo.h"
using namespace std;

/**
 * Comprueba la funcionalidad del operador de suma y del
 * operador de resta.
 */
int main(void) {
    TPoro a(0, 1, 5), b(0, 1, 6), c(3, 4, 7);
    TListaPoro lista1, lista2;

    lista1.Insertar(a);
    lista1.Insertar(b);
    lista2.Insertar(b);
    lista2.Insertar(c);

    TListaPoro lista = lista1 + lista2;

    TListaPosicion pos = lista.Primera();
    while (!pos.EsVacia()) {
        cout << lista.Obtener(pos) << endl;
        pos = pos.Siguiente();
    }

    TListaPoro otralista = lista1 - lista2;

    pos = otralista.Primera();
    while (!pos.EsVacia()) {
        cout << otralista.Obtener(pos) << endl;
        pos = pos.Siguiente();
    }

    return 0;
}