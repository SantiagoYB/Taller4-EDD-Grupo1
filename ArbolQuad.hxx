#include "ArbolQuad.h"

template < class T >
ArbolQuad<T>::ArbolQuad(){
    this->raiz = NULL;
};

template < class T >
ArbolQuad<T>::ArbolQuad(T val){
    
    NodoQuad<T> * nodo = new NodoQuad<T>;
    nodo->fijarDato(val);
    this->raiz = nodo;
};

template < class T >
ArbolQuad<T>::~ArbolQuad() {
    if (this->raiz != NULL){
        delete this->raiz;
        this->raiz = NULL;
    } 
};

template < class T >
bool ArbolQuad<T>::esVacio() {
    return this->raiz == NULL; //Si no tenemos raiz, el arbol es vacio.
};

template < class T >
NodoQuad<T>* ArbolQuad<T>::obtenerRaiz() {
    return this->raiz;
};

template < class T >
void ArbolQuad<T>::fijarRaiz(NodoQuad<T>* n_raiz) {
    this->raiz = n_raiz;
};

template < class T >
bool ArbolQuad<T>::insertarNodo(T val) {
    NodoQuad<T> *nodo = new NodoQuad<T>;
    nodo->fijarDato(val);
    //Buscar nodo padre
    buscarSiguienteNodo(this->raiz, val, nodo);
    
    return true;
};


template < class T >
void ArbolQuad<T>::buscarSiguienteNodo(NodoQuad<T> *nodo, T val, NodoQuad<T> *nuevo) {
    if(nodo->obtenerHijoSupIzq() == nullptr) {
        nodo->fijarHijoSupIzq(nuevo);
        return;
    }
    else if (nodo->obtenerHijoSupIzq()->obtenerDato() == 2) {
        buscarSiguienteNodo(nodo->obtenerHijoSupIzq(), val,nuevo);
    }

    if(nodo->obtenerHijoSupDer() == nullptr) {
        nodo->fijarHijoSupDer(nuevo);
        return;
    }
    else if (nodo->obtenerHijoSupDer()->obtenerDato() == 2) {
        buscarSiguienteNodo(nodo->obtenerHijoSupDer(), val,nuevo);
    }

    if(nodo->obtenerHijoInfDer() == nullptr) {
        nodo->fijarHijoInfDer(nuevo);
        return;
    }
    else if (nodo->obtenerHijoInfDer()->obtenerDato() == 2) {
        buscarSiguienteNodo(nodo->obtenerHijoInfDer(), val, nuevo);
    }

    if(nodo->obtenerHijoInfIzq() == nullptr) {
        nodo->fijarHijoInfIzq(nuevo);
        return;
    }
    else if (nodo->obtenerHijoInfIzq()->obtenerDato() == 2) {
        buscarSiguienteNodo(nodo->obtenerHijoInfIzq(), val, nuevo);
    }
}


template < class T >
void ArbolQuad<T>::preOrden() {
    if(!this->esVacio()){
        this->preOrden(this->raiz);
    }
};

template < class T >
void ArbolQuad<T>::preOrden(NodoQuad<T>* nodo) {
    std::cout << " " <<nodo->obtenerDato();
    if(nodo->obtenerHijoSupIzq() != nullptr) {
        this->preOrden(nodo->obtenerHijoSupIzq());
    }

    if(nodo->obtenerHijoSupDer() != nullptr) {
        this->preOrden(nodo->obtenerHijoSupDer());
    }

    if(nodo->obtenerHijoInfDer() != nullptr) {
        this->preOrden(nodo->obtenerHijoInfDer());
    }

    if(nodo->obtenerHijoInfIzq() != nullptr) {
        this->preOrden(nodo->obtenerHijoInfIzq());
    }

};

template < class T >
void ArbolQuad<T>::inOrden() {
}

template < class T >
void ArbolQuad<T>::inOrden(NodoQuad<T>* nodo) {

};
                
template < class T >     
void ArbolQuad<T>::posOrden() {

};

template < class T >
void ArbolQuad<T>::posOrden(NodoQuad<T>* nodo) {

};

template < class T >
void ArbolQuad<T>::nivelOrden() {

};



        
        
