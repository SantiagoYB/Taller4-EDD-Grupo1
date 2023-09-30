#ifndef _NodoQuad_H__
#define _NodoQuad_H__

template < class T >
struct NodoQuad {
    protected:
        Punto<T> pos;
        T data;
    public:
        NodoQuad(Punto<T> _pos, T _data);
        NodoQuad();
        Punto<T> obtenerPosicion();
        T obtenerData();
};

#include "NodoQuad.hxx"

#endif