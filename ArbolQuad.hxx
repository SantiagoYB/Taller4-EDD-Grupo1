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
    return true;
};

template < class T >
void ArbolQuad<T>::preOrden() {
    if(!this->esVacio()){
        this->preOrden(this->raiz);
    }
};

template < class T >
void ArbolQuad<T>::preOrden(NodoQuad<T>* nodo) {
    std::cout << " " <<this->obtenerDato();
    if(nodo->hijoSupIzq != nullptr) {
        this->preOrden(nodo->hijoSupIzq);
    }
    if(nodo->hijoSupDer != nullptr) {
        this->preOrden(nodo->hijoSupDer);
    }
    if(nodo->hijoInfIzq != nullptr) {
        this->preOrden(nodo->hijoInfIzq);
    }
    if(nodo->hijoInfDer != nullptr) {
        this->preOrden(nodo->hijoInfDer);
    }
};

template < class T >
void ArbolQuad<T>::inOrden() {
    if(!this->esVacio()){
        
        if(this->raiz->hijoSupIzq == nullptr) {
            this->inOrden(this->raiz->hijoSupIzq);
        }
        if(this->raiz->hijoSupDer == nullptr) {
            this->inOrden(this->raiz->hijoSupDer);
        }
        std::cout << " " <<this->obtenerDato();
        if(this->raiz->hijoInfIzq == nullptr) {
            this->inOrden(this->raiz->hijoInfIzq);
        }
        if(this->raiz->hijoInfDer == nullptr) {
            this->inOrden(this->raiz->hijoInfDer);
        }
        
    }
}

template < class T >
void ArbolQuad<T>::inOrden(NodoQuad<T>* nodo) {
    if(nodo->hijoSupIzq == nullptr) {
        this->inOrden(nodo->hijoSupIzq);
    }
    if(nodo->hijoSupDer == nullptr) {
        this->inOrden(nodo->hijoSupDer);
    }
    std::cout << " " <<this->obtenerDato();
    if(nodo->hijoInfIzq == nullptr) {
        this->inOrden(nodo->hijoInfIzq);
    }
    if(nodo->hijoInfDer == nullptr) {
        this->inOrden(nodo->hijoInfDer);
    }
    
};
                
template < class T >     
void ArbolQuad<T>::posOrden() {
    if(!this->esVacio()){
        
        if(this->raiz->hijoSupIzq == nullptr) {
            this->posOrden(this->raiz->hijoSupIzq);
        }
        if(this->raiz->hijoSupDer == nullptr) {
            this->posOrden(this->raiz->hijoSupDer);
        }
        if(this->raiz->hijoInfIzq == nullptr) {
            this->posOrden(this->raiz->hijoInfIzq);
        }
        if(this->raiz->hijoInfDer == nullptr) {
            this->posOrden(this->raiz->hijoInfDer);
        }
        std::cout << " " <<this->obtenerDato();
    }
};

template < class T >
void ArbolQuad<T>::posOrden(NodoQuad<T>* nodo) {
    
    if(nodo->hijoSupIzq == nullptr) {
        this->posOrden(nodo->hijoSupIzq);
    }
    if(nodo->hijoSupDer == nullptr) {
        this->posOrden(nodo->hijoSupDer);
    }
    if(nodo->hijoInfIzq == nullptr) {
        this->posOrden(nodo->hijoInfIzq);
    }
    if(nodo->hijoInfDer == nullptr) {
        this->posOrden(nodo->hijoInfDer);
    }
    std::cout << " " <<this->obtenerDato();
};

template < class T >
void ArbolQuad<T>::nivelOrden() {

};



        
        
