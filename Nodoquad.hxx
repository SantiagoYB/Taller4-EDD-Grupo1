#include "NodoQuad.h"

NodoQuad::NodoQuad() {
  this->hijoSupIzq = NULL;
  this->hijoSupDer = NULL;
  this->hijoInfIzq = NULL;
  this->hijoInfDer = NULL;
}

NodoQuad::NodoQuad(int val) {
  this->dato = val;
  this->hijoSupIzq = NULL;
  this->hijoSupDer = NULL;
  this->hijoInfIzq = NULL;
  this->hijoInfDer = NULL;
}

NodoQuad::~NodoQuad() {
  if (this->hijoSupIzq != NULL){
    delete this->hijoSupIzq ;
    this->hijoSupIzq = NULL;
  }
  if(this->hijoSupDer != NULL){
    delete this->hijoSupDer;
    this->hijoSupDer = NULL;
  }
}

int NodoQuad::obtenerDato() {
  return this->dato;
}

NodoQuad* NodoQuad::obtenerHijoSupIzq() {
  return this->hijoSupIzq;
}

NodoQuad* NodoQuad::obtenerHijoSupDer() {
  return this->hijoSupDer;
}

NodoQuad* NodoQuad::obtenerHijoInfIzq() {
  return this->hijoInfIzq;
}

NodoQuad* NodoQuad::obtenerHijoInfDer() {
  return this->hijoInfDer;
}

void NodoQuad::fijarDato(int val) {
  this->dato = val;
}

void NodoQuad::fijarHijoSupIzq(NodoQuad* sizq) {
  this->hijoSupIzq = sizq;
}

void NodoQuad::fijarHijoSupDer(NodoQuad* sder) {
  this->hijoSupDer = sder;
}

void NodoQuad::fijarHijoInfIzq(NodoQuad* iizq) {
  this->hijoInfIzq = iizq;
}

void NodoQuad::fijarHijoInfDer(NodoQuad* ider) {
  this->hijoInfDer = ider;
}

bool NodoQuad::esHoja() {
  return (this->hijoSupIzq == NULL && this->hijoSupDer == NULL && this->hijoInfIzq == NULL && this->hijoInfDer == NULL);
}

bool NodoQuad::esCompleto() {
  return (this->hijoSupIzq != NULL && this->hijoSupDer != NULL && this->hijoInfIzq != NULL && this->hijoInfDer != NULL);
}