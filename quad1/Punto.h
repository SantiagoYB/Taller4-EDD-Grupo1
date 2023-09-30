#ifndef _Punto_H__
#define _Punto_H__

template < class T >
class Punto {
    private:
        T x;
        T y;
    public:
        Punto();
        Punto(T valor_x, T valor_y);
        T obtenerX();
        T obtenerY();
};

#include "Punto.hxx"

#endif