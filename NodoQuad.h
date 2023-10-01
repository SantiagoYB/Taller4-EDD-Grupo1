#ifndef __NODOQUAD_H__
#define __NODOQUAD_H__

class NodoQuad {
  private:
    int dato;
    NodoQuad* hijoSupIzq;
    NodoQuad* hijoSupDer;
    NodoQuad* hijoInfIzq;
    NodoQuad* hijoInfDer;
  public:
    NodoQuad();
    NodoQuad(int val);
    ~NodoQuad();

    int obtenerDato();
    void fijarDato(int val);

    NodoQuad* obtenerHijoSupIzq();
    NodoQuad* obtenerHijoSupDer();
    NodoQuad* obtenerHijoInfIzq();
    NodoQuad* obtenerHijoInfDer();

    void fijarHijoSupIzq(NodoQuad* sizq);
    void fijarHijoSupDer(NodoQuad* sder);
    void fijarHijoInfIzq(NodoQuad* iizq);
    void fijarHijoInfDer(NodoQuad* ider);

    bool esHoja();
    bool esCompleto();
};

#include "NodoQuad.hxx"

#endif