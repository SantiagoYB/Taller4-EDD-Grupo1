#include "QuadTree.h"
#include "NodoQuad.h"

template < class T >
QuadTree<T>::QuadTree(){
    topLeft = Punto<T>(0, 0);
    botRight = Punto<T>(0, 0);
    n = NULL;
    topLeftQuadTree = NULL;
    topRightQuadTree = NULL;
    botLeftQuadTree = NULL;
    botRightQuadTree = NULL;
}

template < class T >
QuadTree<T>::QuadTree(Punto<T> topL, Punto<T> botR){
    n = NULL;
    topLeftQuadTree = NULL;
    topRightQuadTree = NULL;
    botLeftQuadTree = NULL;
    botRightQuadTree = NULL;
    topLeft = topL;
    botRight = botR;
}

template < class T >
void QuadTree<T>::insert(NodoQuad<T>* node)
{
    if (node == NULL)
        return;
 
    // Revisar si el nodo esta dentro de los limites
    if (!inBoundary(node->obtenerPosicion()))
        return;
 
    // We are at a QuadTree of unit area
    // Revisar si el quadTree no puede subdividirse
    if (abs(topLeft.x - botRight.x) <= 1
        && abs(topLeft.y - botRight.y) <= 1) {
        if (n == NULL)
            n = node;
        return;
    }
 
    if ((topLeft.x + botRight.x) / 2 >= node->obtenerPosicion().x) {
        // Esquina superior izquierda
        if ((topLeft.y + botRight.y) / 2 >= node->obtenerPosicion().y) {
            if (topLeftQuadTree == NULL)
                topLeftQuadTree = new QuadTree(
                    Punto<T>(topLeft.x, topLeft.y),
                    Punto<T>((topLeft.x + botRight.x) / 2,
                          (topLeft.y + botRight.y) / 2));
            topLeftQuadTree->insert(node);
        }
 
        // Esquina inferior izquierda
        else {
            if (botLeftQuadTree == NULL)
                botLeftQuadTree = new QuadTree(
                    Punto<T>(topLeft.x,
                          (topLeft.y + botRight.y) / 2),
                    Punto<T>((topLeft.x + botRight.x) / 2,
                          botRight.y));
            botLeftQuadTree->insert(node);
        }
    }
    else {
        // Esquina superior derecha
        if ((topLeft.y + botRight.y) / 2 >= node->obtenerPosicion().y) {
            if (topRightQuadTree == NULL)
                topRightQuadTree = new QuadTree(
                    Punto<T>((topLeft.x + botRight.x) / 2,
                          topLeft.y),
                    Punto<T>(botRight.x,
                          (topLeft.y + botRight.y) / 2));
            topRightQuadTree->insert(node);
        }
 
        // Esquina inferior derecha
        else {
            if (botRightQuadTree == NULL)
                botRightQuadTree = new QuadTree(
                    Punto<T>((topLeft.x + botRight.x) / 2,
                          (topLeft.y + botRight.y) / 2),
                    Punto<T>(botRight.x, botRight.y));
            botRightQuadTree->insert(node);
        }
    }
}

// Revisar que el nodo esta dentro de los limites del QuadTree
template < class T >
bool QuadTree<T>::inBoundary(Punto<T> p)
{
    return (p.x >= topLeft.x && p.x <= botRight.x && p.y >= topLeft.y && p.y <= botRight.y);
}


template < class T >
NodoQuad<T>* QuadTree<T>::search(Punto<T> p)
{
    // Buscar si se esta buscando un punto dentro de los limites del QuadTree
    if (!inBoundary(p))
        return NULL;
 
    // We are at a quad of unit length
    // Revisar si el quadTree no puede subdividirse
    if (n != NULL)
        return n;
 
    if ((topLeft.x + botRight.x) / 2 >= p.x) {
        // Esquina superior izquierda
        if ((topLeft.y + botRight.y) / 2 >= p.y) {
            if (topLeftQuadTree == NULL)
                return NULL;
            return topLeftQuadTree->search(p);
        }
 
        // Esquina inferior izquierda
        else {
            if (botLeftQuadTree == NULL)
                return NULL;
            return botLeftQuadTree->search(p);
        }
    }
    else {
        // Esquina superior derecha
        if ((topLeft.y + botRight.y) / 2 >= p.y) {
            if (topRightQuadTree == NULL)
                return NULL;
            return topRightQuadTree->search(p);
        }
 
        // Esquina inferior derecha
        else {
            if (botRightQuadTree == NULL)
                return NULL;
            return botRightQuadTree->search(p);
        }
    }
};