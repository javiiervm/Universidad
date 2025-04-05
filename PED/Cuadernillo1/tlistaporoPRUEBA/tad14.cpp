#include <iostream>
#include "tlistaporo.h"
using namespace std;

/**
 * Si la lista contiene un elemento TPoro vacío, NO podrá
 * haber otro igual.
 */
int main(void) {
    TPoro a, b; // vacios
    TListaPoro lista;

    if (lista.Insertar(a)) cout << "correcto" << endl;
    if (!lista.Insertar(b)) cout << "correcto" << endl;
    cout << lista.Longitud() << endl;
    
    return 0;
}