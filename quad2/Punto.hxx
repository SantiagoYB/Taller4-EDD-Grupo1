#include "Punto.h"

template < class T >
Punto<T>::Punto() {
    x = 0;
    y = 0;
}

template < class T >
Punto<T>::Punto(T valor_x, T valor_y){
    x = valor_x;
    y = valor_y;
}

template < class T >
T Punto<T>::obtenerX(){
    return x;
}

template < class T >
T Punto<T>::obtenerY(){
    return y;
}