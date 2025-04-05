#include <iostream>
#include "tporo.h"

using namespace std;

/**
 * Norma 5: condiciones del operador de igualdad
 * (operator==).
 */
int main(void) {
    TPoro a(25, 0, 1.25), b(25, 0, 1.25, "Blanco");

    if (a != b)
        cout << "Correcto" << endl;
    
    a.Color("blaNco");
    if (a == b)
        cout << "Correcto" << endl;
    
    b.Volumen(1.15);
    if (a != b)
        cout << "Correcto" << endl;
    
    b.Volumen(1.25);
    if (a == b)
        cout << "Correcto" << endl;
    
    a.Posicion(25, 1);
    if (a != b)
        cout << "Correcto" << endl;
    return 0;
}