#include <iostream>

using namespace std;

#include "tporo.h"

/**
 * Comprueba norma 1: valores por defecto de TPoro
 * - Posicion: (0,0)
 * - Volumen: 0
 * - Color: NULL
 */
int
main(void)
{
  TPoro a, b;

  cout << a.PosicionX() << " " << a.PosicionY() << endl;
  cout << b.Volumen() << endl;
  
  if (b.Color() == NULL)
    cout << "Color es nulo" << endl;

  return 0;
}
