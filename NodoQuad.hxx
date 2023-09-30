#include "Punto.h"
#include "NodoQuad.h"

template < class T >
NodoQuad<T>::NodoQuad() { 
    data = 0; 
}
template < class T >
NodoQuad<T>::NodoQuad(Punto<T> _pos, T _data){
    pos = _pos;
    data = _data;
}

template < class T >
Punto<T> NodoQuad<T>::obtenerPosicion() {
    return this->pos;
}

template < class T >
T NodoQuad<T>::obtenerData() {
    return this->data;
}
