#include "ArbolQuad.h"
#include <iostream>

ArbolQuad::ArbolQuad(){
    this->raiz = NULL;
};

ArbolQuad::ArbolQuad(int val){
    NodoQuad* nodo = new NodoQuad;
    nodo->fijarDato(val);
    this->raiz = nodo;
};

ArbolQuad::~ArbolQuad() {
    if (this->raiz != NULL){
        delete this->raiz;
        this->raiz = NULL;
    } 
};

bool ArbolQuad::esVacio() {
    return this->raiz == NULL;
};

NodoQuad* ArbolQuad::obtenerRaiz() {
    return this->raiz;
};

void ArbolQuad::fijarRaiz(NodoQuad* n_raiz) {
    this->raiz = n_raiz;
};

bool ArbolQuad::insertarNodo(int val) {
    NodoQuad* nodo = new NodoQuad();
    nodo->fijarDato(val);
    // Buscar nodo padre
    buscarSiguienteNodo(this->raiz, val, nodo);
    
    return true;
};

void ArbolQuad::buscarSiguienteNodo(NodoQuad* nodo, int val, NodoQuad* nuevo) {
    if (nodo->obtenerHijoSupIzq() == nullptr) {
        nodo->fijarHijoSupIzq(nuevo);
        return;
    }
    else if (nodo->obtenerHijoSupIzq()->obtenerDato() == 2) {
        buscarSiguienteNodo(nodo->obtenerHijoSupIzq(), val, nuevo);
    }

    if (nodo->obtenerHijoSupDer() == nullptr) {
        nodo->fijarHijoSupDer(nuevo);
        return;
    }
    else if (nodo->obtenerHijoSupDer()->obtenerDato() == 2) {
        buscarSiguienteNodo(nodo->obtenerHijoSupDer(), val, nuevo);
    }

    if (nodo->obtenerHijoInfDer() == nullptr) {
        nodo->fijarHijoInfDer(nuevo);
        return;
    }
    else if (nodo->obtenerHijoInfDer()->obtenerDato() == 2) {
        buscarSiguienteNodo(nodo->obtenerHijoInfDer(), val, nuevo);
    }

    if (nodo->obtenerHijoInfIzq() == nullptr) {
        nodo->fijarHijoInfIzq(nuevo);
        return;
    }
    else if (nodo->obtenerHijoInfIzq()->obtenerDato() == 2) {
        buscarSiguienteNodo(nodo->obtenerHijoInfIzq(), val, nuevo);
    }
}

void ArbolQuad::preOrden() {
    if (!this->esVacio()) {
        this->preOrden(this->raiz);
    }
};

void ArbolQuad::preOrden(NodoQuad* nodo) {
    std::cout << " " << nodo->obtenerDato();
    if (nodo->obtenerHijoSupIzq() != nullptr) {
        this->preOrden(nodo->obtenerHijoSupIzq());
    }

    if (nodo->obtenerHijoSupDer() != nullptr) {
        this->preOrden(nodo->obtenerHijoSupDer());
    }

    if (nodo->obtenerHijoInfDer() != nullptr) {
        this->preOrden(nodo->obtenerHijoInfDer());
    }

    if (nodo->obtenerHijoInfIzq() != nullptr) {
        this->preOrden(nodo->obtenerHijoInfIzq());
    }
}

void ArbolQuad::inOrden() {
}

void ArbolQuad::inOrden(NodoQuad* nodo) {
}

void ArbolQuad::posOrden() {
}

void ArbolQuad::posOrden(NodoQuad* nodo) {
}

void ArbolQuad::nivelOrden() {
}
