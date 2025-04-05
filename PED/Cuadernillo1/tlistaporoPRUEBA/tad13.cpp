#include <iostream>
#include "tlistaporo.h"
using namespace std;

int main(void) {
    TListaPoro listavacia, listanovacia;
    TPoro a(1,2,3,"azul"), b(4,5,6, "verde"), c(7,8,9);

    listanovacia.Insertar(a);
    listanovacia.Insertar(b);
    listanovacia.Insertar(c);

    cout << listanovacia.Longitud() << endl;
    cout << listavacia.Longitud() << endl;

    listanovacia = listavacia;
    cout << listanovacia.Longitud() << endl;
    return 0;
}