#include "NodoQuad.h"

template < class T>
NodoQuad<T>::NodoQuad() {
  this->hijoSupIzq = nullptr;
  this->hijoSupDer = nullptr;
  this->hijoInfIzq = nullptr;
  this->hijoInfDer = nullptr;
}

template < class T>
NodoQuad<T>::NodoQuad(T val) {
  this->dato = val;
  this->hijoSupIzq = nullptr;
  this->hijoSupDer = nullptr;
  this->hijoInfIzq = nullptr;
  this->hijoInfDer = nullptr;
}

template < class T>
NodoQuad<T>::~NodoQuad() {
  if (this->hijoSupIzq != nullptr){
    delete this->hijoSupIzq ;
    this->hijoSupIzq = nullptr;
  }
  if(this->hijoSupDer != nullptr){
    delete this->hijoSupDer;
    this->hijoSupDer = nullptr;
  }
}


template < class T>
T NodoQuad<T>::obtenerDato() {
  return this ->dato;
}

template < class T>
NodoQuad<T>* NodoQuad<T>::obtenerHijoSupIzq() {
  return this->hijoSupIzq;
}

template < class T>
NodoQuad<T>* NodoQuad<T>::obtenerHijoSupDer() {
  return this->hijoSupDer;
}

template < class T>
NodoQuad<T>* NodoQuad<T>::obtenerHijoInfIzq() {
  return this->hijoInfIzq;
}

template < class T>
NodoQuad<T>* NodoQuad<T>::obtenerHijoInfDer() {
  return this->hijoInfDer;
}

template < class T>
void NodoQuad<T>::fijarDato(T val) {
  this->dato = val;
}

template < class T>
void NodoQuad<T>::fijarHijoSupIzq(NodoQuad<T>* sizq) {
  this->hijoSupIzq = sizq;
}

template < class T >
void NodoQuad<T>::fijarHijoSupDer(NodoQuad<T>* sder) {
  this->hijoSupDer = sder;
}

template < class T >
void NodoQuad<T>::fijarHijoInfIzq(NodoQuad<T>* iizq) {
  this->hijoInfIzq = iizq;
}

template < class T >
void NodoQuad<T>::fijarHijoInfDer(NodoQuad<T>* ider) {
  this->hijoInfDer = ider;
}



template < class T >
bool NodoQuad<T>::esHoja() {
  return (this->hijoSupIzq == nullptr && this->hijoSupDer == nullptr && this->hijoInfIzq == nullptr && this->hijoInfDer == nullptr);
}