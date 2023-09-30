#ifndef _ArbolQuad_H__
#define _ArbolQuad_H__

#include "NodoQuad.h"

template < class T >
class ArbolQuad {
  protected:
      NodoQuad<T>* raiz;
  public:
      ArbolQuad();
      ArbolQuad(T val);
      ~ArbolQuad();
      NodoQuad<T>* obtenerRaiz();
      void fijarRaiz(NodoQuad<T>* n_raiz);
      bool esVacio();
      bool insertarNodo(T val);
      void preOrden();
      void preOrden(NodoQuad<T>* nodo);
      void inOrden();
      void inOrden(NodoQuad<T>* nodo);
      void posOrden();
      void posOrden(NodoQuad<T>* nodo);
      void nivelOrden();
};

#include "ArbolQuad.hxx"

#endif