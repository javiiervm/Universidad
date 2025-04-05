#include <iostream>
#include "tporo.h"

using namespace std;

/**
 * Norma 3: los nombres de los colores se almacenarán siempre
 * en minúsculas.
 */
int main(void) {
    TPoro a, b, c;

    a.Color("Verde");
    b.Color("AzUl CiElO");
    c.Color("AMARILLO FOSFORITO");

    cout << a.Color() << endl;
    cout << b.Color() << endl;
    cout << c.Color() << endl;

    return 0;
}