#ifndef _ARBOLQUAD_H__
#define _ARBOLQUAD_H__

#include "NodoQuad.h"

class ArbolQuad {
  protected:
    NodoQuad* raiz;
  public:
    ArbolQuad();
    ArbolQuad(int val);
    ~ArbolQuad();
    bool esVacio();

    NodoQuad* obtenerRaiz();
    void fijarRaiz(NodoQuad* n_raiz);
    bool insertarNodo(int val);

    void buscarSiguienteNodo(NodoQuad* nodo, int val, NodoQuad* nuevo);

    void preOrden();
    void preOrden(NodoQuad* nodo);
    void inOrden();
    void inOrden(NodoQuad* nodo);
    void posOrden();
    void posOrden(NodoQuad* nodo);
    void nivelOrden();
};

#include "ArbolQuad.hxx"

#endif