#ifndef _QuadTree_H__
#define _QuadTree_H__

#include "NodoQuad.h"

template < class T >
class QuadTree {
    protected:
        Punto<T> topLeft;
        Punto<T> botRight;
        NodoQuad<T>* n;
        QuadTree<T>* topLeftQuadTree;
        QuadTree<T>* topRightQuadTree;
        QuadTree<T>* botLeftQuadTree;
        QuadTree<T>* botRightQuadTree;
    public:
        QuadTree();
        QuadTree(Punto<T> topL, Punto<T> botR);
        void insert(NodoQuad<T>* NodoQuad);
        NodoQuad<T>* search(Punto<T>);
        bool inBoundary(Punto<T>);
};

#include "QuadTree.hxx"

#endif