
/*
#include "ArbolQuad.h"

bool ArbolQuad::insertarNodoRecursivo(NodoQuad* nodo, int val){
    
    if (nodo->obtenerDato() == 2){
        if(nodo->obtenerHijoSupIzq() == NULL || nodo->obtenerHijoSupIzq()->obtenerDato() == 2){
            //El hijo no existe, crea un nuevo y establece el dato.
            if(nodo->obtenerHijoSupIzq() == NULL) {
                NodoQuad* nodoInsertar = new NodoQuad();
                nodoInsertar->fijarDato(val);
                nodo->fijarHijoSupIzq(nodoInsertar);
                return true;
            }else if(nodo->obtenerHijoSupIzq()->esCompleto()){
                // Padre inserta en el siguiente
                NodoQuad* nodoInsertar = new NodoQuad();
                nodoInsertar->fijarDato(val);
                NodoQuad* padre = encontrarPadre(nodo);
                padre->fijarHijoSupDer(nodoInsertar);
                return true;
            }else if(nodo->obtenerHijoSupIzq()->obtenerDato() == 2){
                //se llama recursion sobre ese nodo
                insertarNodoRecursivo(nodo->obtenerHijoSupIzq(), val);
            }
        } 
        else if (nodo->obtenerHijoSupDer() == NULL || nodo->obtenerHijoSupDer()->obtenerDato() == 2){
            //El hijo no existe, crea uno nuevo y establece el dato.
            if(nodo->obtenerHijoSupDer() == NULL){
                NodoQuad* nodoInsertar = new NodoQuad();
                nodoInsertar->fijarDato(val);
                nodo->fijarHijoSupDer(nodoInsertar);
                return true;
            } else if(nodo->obtenerHijoSupDer()->esCompleto()){
                // Padre inserta en el siguiente
                NodoQuad* nodoInsertar = new NodoQuad();
                nodoInsertar->fijarDato(val);
                NodoQuad* padre = encontrarPadre(nodo);
                padre->fijarHijoInfDer(nodoInsertar);
                return true;
            }else if(nodo->obtenerHijoSupDer()->obtenerDato() == 2){
                //se llama recursion sobre ese nodo
                insertarNodoRecursivo(nodo->obtenerHijoSupDer(), val);
            }
        } 
        else if (nodo->obtenerHijoInfDer() == NULL || nodo->obtenerHijoInfDer()->obtenerDato() == 2){
            //El hijo no existe, crea uno nuevo y establece el dato.
            if(nodo->obtenerHijoInfDer() == NULL){
                NodoQuad* nodoInsertar = new NodoQuad();
                nodoInsertar->fijarDato(val);
                nodo->fijarHijoInfDer(nodoInsertar);
                return true;
            } else if(nodo->obtenerHijoInfDer()->esCompleto()){
                // Padre inserta en el siguiente
                NodoQuad* nodoInsertar = new NodoQuad();
                nodoInsertar->fijarDato(val);
                NodoQuad* padre = encontrarPadre(nodo);
                padre->fijarHijoInfIzq(nodoInsertar);
                return true;
            } else if(nodo->obtenerHijoInfDer()->obtenerDato() == 2){
                //se llama recursion sobre ese nodo
                insertarNodoRecursivo(nodo->obtenerHijoInfDer(), val);
            }
        } 
        else if(nodo->obtenerHijoInfIzq() == NULL || nodo->obtenerHijoInfIzq()->obtenerDato() == 2){
            //El hijo no existe, crea uno nuevo y establece el dato.
            if(nodo->obtenerHijoInfIzq() == NULL) {
                NodoQuad* nodoInsertar = new NodoQuad();
                nodoInsertar->fijarDato(val);
                nodo->fijarHijoInfIzq(nodoInsertar);
                return true;
            } else if(nodo->obtenerHijoInfIzq()->esCompleto()){
                // Padre inserta en el siguiente
                NodoQuad* nodoInsertar = new NodoQuad();
                nodoInsertar->fijarDato(val);
                NodoQuad* padre = encontrarPadre(nodo);
                padre->fijarHijoSupIzq(nodoInsertar);
                return true;
            }else if(nodo->obtenerHijoInfIzq()->obtenerDato() == 2){
                insertarNodoRecursivo(nodo->obtenerHijoInfIzq(), val);
            }
        }
    }

    return false;
};
*/
