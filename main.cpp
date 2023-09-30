
#include <cmath>
#include <iostream>
using namespace std;

#include "Punto.h"
#include "QuadTree.h"
#include "NodoQuad.h"
 
int main()
{
    QuadTree<int> arbol(Punto<int>(0, 0), Punto<int>(8, 8));
    NodoQuad<int> a(Punto<int>(1, 1), 1);
    NodoQuad<int> b(Punto<int>(2, 5), 2);
    NodoQuad<int> c(Punto<int>(7, 6), 3);
    arbol.insert(&a);
    arbol.insert(&b);
    arbol.insert(&c);
    cout << "Buscar nodo a: " << arbol.search(Punto<int>(1, 1))->obtenerData() << "\n";
    cout << "Buscar nodo b: " << arbol.search(Punto<int>(2, 5))->obtenerData() << "\n";
    cout << "Buscar nodo c: " << arbol.search(Punto<int>(7, 6))->obtenerData() << "\n";
    cout << "Nodo que no existe: " << arbol.search(Punto<int>(5, 5));
    return 0;
}