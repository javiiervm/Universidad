#include <iostream>
#include "tlistaporo.h"
using namespace std;

/**
 * Comprueba que el constructor de copia también funciona sobre
 * listas vacías.
 */
int main(void) {
    TListaPoro listavacia;
    TListaPoro otralistavacia(listavacia);
    cout << listavacia.Longitud() << endl;
    cout << otralistavacia.Longitud() << endl;

    cout << boolalpha << listavacia.EsVacia() << endl
        << otralistavacia.EsVacia() << noboolalpha << endl;
    return 0;
}