#include "ArbolQuad.h"
#include "NodoQuad.h"

template < class T >
ArbolQuad<T>::ArbolQuad(){
    this->raiz = NULL;
};

template < class T >
ArbolQuad<T>::ArbolQuad(T val){
};

template < class T >
ArbolQuad<T>::~ArbolQuad() {
    if (this->raiz != NULL){
        delete this->raiz;
        this->raiz = NULL;
    } 
};

template < class T >
NodoQuad<T>* ArbolQuad<T>::obtenerRaiz() {
    return this->raiz;
};

template < class T >
void fijarRaiz(NodoQuad<T>* n_raiz) {

};

template < class T >
bool esVacio() {
    
};

template < class T >
bool insertarNodo(T val) {
    
};

template < class T >
void preOrden() {
    if(!this->esVacio()){
        std::cout << " " <<this->obtenerDato();
        if(this->raiz->hijoSupIzq == nullptr) {
            this->preOrden(this->raiz->hijoSupIzq);
        }
        if(this->raiz->hijoSupDer == nullptr) {
            this->preOrden(this->raiz->hijoSupDer);
        }
        if(this->raiz->hijoInfIzq == nullptr) {
            this->preOrden(this->raiz->hijoInfIzq);
        }
        if(this->raiz->hijoInfDer == nullptr) {
            this->preOrden(this->raiz->hijoInfDer);
        }
    }
};

template < class T >
void preOrden(NodoQuad<T>* nodo) {
    std::cout << " " <<this->obtenerDato();
    if(nodo->hijoSupIzq == nullptr) {
        this->preOrden(nodo->hijoSupIzq);
    }
    if(nodo->hijoSupDer == nullptr) {
        this->preOrden(nodo->hijoSupDer);
    }
    if(nodo->hijoInfIzq == nullptr) {
        this->preOrden(nodo->hijoInfIzq);
    }
    if(nodo->hijoInfDer == nullptr) {
        this->preOrden(nodo->hijoInfDer);
    }
};

template < class T >
void inOrden() {

}

template < class T >
void inOrden(NodoQuad<T>* nodo) {

};
                
template < class T >     
void posOrden() {
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
void posOrden(NodoQuad<T>* nodo) {
    
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
void nivelOrden() {

};



        
        
