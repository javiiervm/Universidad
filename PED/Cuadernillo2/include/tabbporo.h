#include "tvectorporo.h"

#ifndef _TABBPORO_H_
#define _TABBPORO_H_

class TNodoAAB;
class TABBPoro;

class TNodoABB {
    friend class TABBPoro;
    private:
        TPoro item;
        TABBPoro iz, de;
    public:
        TNodoABB();
        TNodoABB(const TNodoABB &other);
        ~TNodoABB();
        TNodoABB & operator=(const TNodoABB &other);
};

class TABBPoro {
    friend class TNodoAAB;
    friend ostream & operator<<(ostream &os, TABBPoro &other);
    private:
        TNodoABB *nodo;
        void InordenAux(TVectorPoro &v, int &i);
        void PreordenAux(TVectorPoro &v, int &i);
        void PostordenAux(TVectorPoro &v, int &i);
        bool esHoja();
        TVectorPoro nivelesSubarbol(TABBPoro subarbol);
    public:
        TABBPoro();
        TABBPoro(TABBPoro &other);
        ~TABBPoro();
        TABBPoro & operator=(const TABBPoro &other);
        bool operator==(TABBPoro &other);
        bool EsVacio();
        bool Insertar(TPoro &other);
        bool Borrar(TPoro &other);
        bool Buscar(TPoro &other);
        TPoro Raiz();
        int Altura();
        int Nodos();
        int NodosHoja();
        TVectorPoro Inorden();
        TVectorPoro Preorden();
        TVectorPoro Postorden();
        TVectorPoro Niveles();
        TABBPoro operator+(TABBPoro &other);
        TABBPoro operator-(TABBPoro &other);
};

#endif