#ifndef __NODOQUAD_H__
#define __NODOQUAD_H__

template < class T >
class NodoQuad {
  private:
      T dato;
      NodoQuad<T>* hijoSupIzq;
      NodoQuad<T>* hijoSupDer;
      NodoQuad<T>* hijoInfIzq;
      NodoQuad<T>* hijoInfDer;
  public:
      NodoQuad();
      NodoQuad(T val);
      ~NodoQuad();

      T obtenerDato();
      NodoQuad<T>* obtenerHijoSupIzq();
      NodoQuad<T>* obtenerHijoSupDer();
      NodoQuad<T>* obtenerHijoInfIzq();
      NodoQuad<T>* obtenerHijoInfDer();

      void fijarDato(T val);
      void fijarHijoSupIzq(NodoQuad<T>* sizq);
      void fijarHijoSupDer(NodoQuad<T>* sder);
      void fijarHijoInfIzq(NodoQuad<T>* iizq);
      void fijarHijoInfDer(NodoQuad<T>* ider);

      bool esHoja();
};

#include "NodoQuad.hxx"

#endif