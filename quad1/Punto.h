#ifndef _Punto_H__
#define _Punto_H__

template < class T >
struct Punto {
    T x;
    T y;
    Punto();
    Punto(T valor_x, T valor_y);
};

#include "Punto.hxx"

#endif