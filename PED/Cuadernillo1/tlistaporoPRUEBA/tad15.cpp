#include <iostream>
#include "tlistaporo.h"
using namespace std;

/**
 * La lista está ordenada de menor a mayor, de acuerdo al volumen del
 * objeto TPoro que contiene el nodo.
 * 
 * También comprueba la funcionalidad de operator==
 */
int main(void) {
    TPoro a(0, 1, 5), b(0, 1, 6), c(3, 4, 7);
    TListaPoro lista;

    lista.Insertar(a);
    lista.Insertar(b);
    lista.Insertar(c);

    TListaPosicion pos = lista.Primera();
    while (!pos.EsVacia()) {
        cout << lista.Obtener(pos) << endl;
        pos = pos.Siguiente();
    }

    TListaPoro otralista(lista);

    cout << boolalpha << (otralista == lista) << noboolalpha << endl;

    return 0;
}