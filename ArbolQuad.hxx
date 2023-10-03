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

int ArbolQuad::datoRaiz() {
    return this->raiz->obtenerDato();
}

NodoQuad* ArbolQuad::obtenerRaiz() {
    return this->raiz;
};

void ArbolQuad::fijarRaiz(NodoQuad* n_raiz) {
    this->raiz = n_raiz;
};

bool ArbolQuad::esVacio() {
    return (this->raiz == NULL);
};

bool ArbolQuad::insertarNodo(int val) {
    
    if(this->esVacio()) {
        this->raiz->fijarDato(val);
        return true;
    } else {
        return this->insertarNodoRecursivo(this->raiz, val);
    }
};

bool ArbolQuad::insertarNodoRecursivo(NodoQuad* nodo, int val){
    bool insertado = false;

    //El hijo no existe, crea un nuevo y establece el dato.
    if(nodo->obtenerHijoSupIzq() == NULL) {
        NodoQuad* nuevo = new NodoQuad(val);
        nodo->fijarHijoSupIzq(nuevo);
        insertado = true;
    } 
    //Si el hijo existe pero es igual a 2 y NO esta completo, llamar recursividad ahi
    else if(nodo->obtenerHijoSupIzq()->obtenerDato() == 2 && !nodo->obtenerHijoSupIzq()->esCompleto()){
        insertado = insertarNodoRecursivo(nodo->obtenerHijoSupIzq(), val);
    }

    if(!insertado){
        //El hijo no existe, crea un nuevo y establece el dato.
        if(nodo->obtenerHijoSupDer() == NULL){
            NodoQuad* nuevo = new NodoQuad(val);
            nodo->fijarHijoSupDer(nuevo);
            insertado = true;
        } 
        //Si el hijo existe pero es igual a 2 y NO esta completo, llamar recursividad ahi
        else if(nodo->obtenerHijoSupDer()->obtenerDato() == 2 && !nodo->obtenerHijoSupDer()->esCompleto()){
            insertado = insertarNodoRecursivo(nodo->obtenerHijoSupDer(), val);
        }
    }

    if(!insertado){
        //El hijo no existe, crea un nuevo y establece el dato.
        if(nodo->obtenerHijoInfDer() == NULL){
            NodoQuad* nuevo = new NodoQuad(val);
            nodo->fijarHijoInfDer(nuevo);
            insertado = true;
        } 
        //Si el hijo existe pero es igual a 2 y NO esta completo, llamar recursividad ahi
        else if(nodo->obtenerHijoInfDer()->obtenerDato() == 2 && !nodo->obtenerHijoInfDer()->esCompleto()){
            insertado = insertarNodoRecursivo(nodo->obtenerHijoInfDer(), val);
        }
    }

    if(!insertado){
        //El hijo no existe, crea un nuevo y establece el dato.
        if(nodo->obtenerHijoInfIzq() == NULL){
            NodoQuad* nuevo = new NodoQuad(val);
            nodo->fijarHijoInfIzq(nuevo);
            insertado = true;
        } 
        //Si el hijo existe pero es igual a 2 y NO esta completo, llamar recursividad ahi
        else if(nodo->obtenerHijoInfIzq()->obtenerDato() == 2 && !nodo->obtenerHijoInfIzq()->esCompleto()){
            insertado = insertarNodoRecursivo(nodo->obtenerHijoInfIzq(), val);
        }
    }

    return insertado;
}

void ArbolQuad::preOrden() {
    if (!this->esVacio()) {
        this->preOrden(this->raiz);
    }
};

void ArbolQuad::preOrden(NodoQuad* nodo) {
    std::cout << " " << nodo->obtenerDato();
    if (nodo->obtenerHijoSupIzq() != NULL) {
        this->preOrden(nodo->obtenerHijoSupIzq());
    }

    if (nodo->obtenerHijoSupDer() != NULL) {
        this->preOrden(nodo->obtenerHijoSupDer());
    }

    if (nodo->obtenerHijoInfDer() != NULL) {
        this->preOrden(nodo->obtenerHijoInfDer());
    }

    if (nodo->obtenerHijoInfIzq() != NULL) {
        this->preOrden(nodo->obtenerHijoInfIzq());
    }
}

int** ArbolQuad::crearMatriz(int tamano) {
    int** matrix = new int*[tamano];
    for (int i = 0; i < tamano; i++) {
        matrix[i] = new int[tamano];
    }
    return matrix;
}

int** ArbolQuad::llenarMatriz(int** matriz, NodoQuad* nodo, int posX, int posY, int tam) {
    if (nodo->obtenerDato() == 1 || nodo->obtenerDato() == 0) {
        int color = nodo->obtenerDato();
        for (int i = posX; i<posX+tam; i++) {
            for (int j = posY; j<posY+tam; j++) {
                matriz[i][j] = color;
            }
        }
    } else {
        // llamar 4 veces, una para cada hijo
        tam = tam/2;
        matriz = llenarMatriz(matriz, nodo->obtenerHijoSupIzq(), posX, posY, tam);
        matriz = llenarMatriz(matriz, nodo->obtenerHijoSupDer(), posX, posY+tam, tam);
        matriz = llenarMatriz(matriz, nodo->obtenerHijoInfDer(), posX+tam, posY+tam, tam);
        matriz = llenarMatriz(matriz, nodo->obtenerHijoInfIzq(), posX+tam, posY, tam);
    }

    return matriz;
}