#include "tabbporo.h"


// =================== TNodoAAB ===================

TNodoABB::TNodoABB() {
    this->item = TPoro();
    this->iz = TABBPoro();
    this->de = TABBPoro();
}

TNodoABB::TNodoABB(const TNodoABB &other) {
    this->item = other.item;
    this->iz = other.iz;
    this->de = other.de;
}

TNodoABB::~TNodoABB() {
    this->item.~TPoro();
    this->iz.~TABBPoro();
    this->de.~TABBPoro();
}

TNodoABB & TNodoABB::operator=(const TNodoABB &other) {
    this->item = other.item;
    this->iz = other.iz;
    this->de = other.de;
    return *this;
}


// =================== TABBPoro ===================

void TABBPoro::InordenAux(TVectorPoro &v, int &i) {

}

void TABBPoro::PreordenAux(TVectorPoro &v, int &i) {

}

void TABBPoro::PostordenAux(TVectorPoro &v, int &i) {

}

TABBPoro::TABBPoro() {
    this->nodo = nullptr;
}

TABBPoro::TABBPoro(TABBPoro &other) {
    this->nodo = other.nodo;
}

TABBPoro::~TABBPoro() {
    if(this->nodo != nullptr) {
        delete this->nodo;
        this->nodo = nullptr;
    }
}

TABBPoro & TABBPoro::operator=(const TABBPoro &other) {
    if (this->nodo != nullptr)
        delete this->nodo;
    this->nodo = other.nodo;
}

bool TABBPoro::operator==(TABBPoro &other) {
    TVectorPoro recorridoThis = this->Niveles();
    recorridoThis.sort();
    TVectorPoro recorridoOther = this->Niveles();
    recorridoOther.sort();
    return recorridoThis == recorridoOther;
}

bool TABBPoro::EsVacio() {
    return this->nodo == nullptr;
}

bool TABBPoro::Insertar(TPoro &other) {
    TNodoABB nuevoItem;
    nuevoItem.item = other;

    TABBPoro *puntero = this;
    while(true) {
        if(puntero->Raiz().Volumen() > other.Volumen()) {   // Hijo izquierdo
            if(puntero->nodo->iz.nodo == nullptr) {
                puntero->nodo->iz.nodo = &nuevoItem;
                return true;
            } else {
                puntero->nodo = puntero->nodo->iz.nodo;
            }
        } else if(puntero->Raiz().Volumen() < other.Volumen()) {    // Hijo derecho
            if(puntero->nodo->de.nodo == nullptr) {
                puntero->nodo->de.nodo = &nuevoItem;
                return true;
            } else {
                puntero->nodo = puntero->nodo->de.nodo;
            }
        } else if(this->EsVacio()) {
            puntero->nodo = &nuevoItem;
        } else {
            break;
        }

        /*
        if(puntero->EsVacio()) {

        }
        */
    }

    return false;
}

bool TABBPoro::Borrar(TPoro &other) {
    TNodoABB *aux = this->nodo;

    while(aux->item != other) {
        if(other.Volumen() > aux->item.Volumen()) {
            if(aux->iz.EsVacio()) return false;
            aux = aux->iz.nodo;
        } else {
            if(aux->de.EsVacio()) return false;
            aux = aux->de.nodo;
        }
    }

    TABBPoro *auxarb;
    TNodoABB *aux2 = nullptr;
    auxarb->nodo = aux;
    if(auxarb->esHoja()) {
        auxarb->nodo->~TNodoABB();
    } else if(auxarb->nodo->de.EsVacio() && !auxarb->nodo->iz.EsVacio()) {
        auxarb = &auxarb->nodo->iz;
    } else if(!auxarb->nodo->de.EsVacio() && auxarb->nodo->iz.EsVacio()) {
        auxarb = &auxarb->nodo->de;
    } else if(!auxarb->nodo->de.EsVacio() && !auxarb->nodo->iz.EsVacio()) {
        aux2 = aux;
        aux = auxarb->nodo->iz.nodo;
        auxarb->nodo = aux;
        while(!auxarb->nodo->de.EsVacio()) {
            aux = auxarb->nodo->de.nodo;
            auxarb->nodo = aux;
        }
        aux2 = aux;
        auxarb->nodo = nullptr;
    }
}

bool TABBPoro::Buscar(TPoro &other) {
    TABBPoro *puntero = this;
    while(true) {
        if(puntero->Raiz().Volumen() > other.Volumen()) {   // Hijo izquierdo
            if(puntero->nodo->iz.nodo == nullptr) {
                return false;
            } else {
                puntero->nodo = puntero->nodo->iz.nodo;
            }
        } else if(puntero->Raiz().Volumen() < other.Volumen()) {    // Hijo derecho
            if(puntero->nodo->de.nodo == nullptr) {
                return false;
            } else {
                puntero->nodo = puntero->nodo->de.nodo;
            }
        } else if(this->EsVacio()) {
            return false;
        } else if(puntero->nodo->item == other) {
            return true;
        }
    }
}

TPoro TABBPoro::Raiz() {
    return this->nodo->item;
}

int TABBPoro::Altura() {
    if(this->EsVacio()) return 0;
    return 1 + (max((this->nodo->iz.Altura()), (this->nodo->de.Altura())));
}

int TABBPoro::Nodos() {
    if(this->EsVacio()) return 0;
    return 1 + this->nodo->iz.Nodos() + this->nodo->de.Nodos();
}

int TABBPoro::NodosHoja() {
    if(this->nodo->de.EsVacio() && this->nodo->iz.EsVacio()) return 1;
    return this->nodo->iz.NodosHoja() + this->nodo->de.NodosHoja();
}

// Devuelve el recorrido en inorden
TVectorPoro TABBPoro::Inorden() {
    // Posición en el vector que almacena el recorrido
    int posicion = 1;
    // Vector del tamaño adecuado para almacenar todos los nodos
    TVectorPoro v(Nodos());
    InordenAux(v, posicion);
    return v;
}

TVectorPoro TABBPoro::Preorden() {

}

TVectorPoro TABBPoro::Postorden() {

}

TVectorPoro TABBPoro::Niveles() {
    // Raiz, raíz izquierdo y raíz derecho
    TVectorPoro solucion;
    
    TVectorPoro nodoActual;
    nodoActual.Redimensionar(1);
    nodoActual.datos[0] = this->nodo->item;
    solucion.Redimensionar(this->Nodos());

    solucion.append(nodoActual);
    solucion.append(nivelesSubarbol(this->nodo->iz));
    solucion.append(nivelesSubarbol(this->nodo->de));

    return solucion;
}

TABBPoro TABBPoro::operator+(TABBPoro &other) {

}

TABBPoro TABBPoro::operator-(TABBPoro &other) {

}

ostream & operator<<(ostream &os, TABBPoro &other) {

}

bool TABBPoro::esHoja() {
    return (!(this->EsVacio()) && this->nodo->de.EsVacio() && this->nodo->iz.EsVacio());
}

TVectorPoro TABBPoro::nivelesSubarbol(TABBPoro subarbol) {
    return subarbol.Niveles();
}
