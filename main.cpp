//Comando para compilar: g++ -std=c++11 main.cpp -o prueba
//Comando para ejecutar: ./prueba
//#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include "ArbolQuad.h"
#include "NodoQuad.h"
 
int main(int argc, char *argv[]){
    std::string nombre_archivo_lectura;
    std::string cinUsuario;

    if (argc < 2) {
        std::cout << "Ingrese el nombre del archivo." << std::endl;
        return 1; // Salir con un código de error
    }
    if(argc - 1 != 1) {
        std::cout << "Ingrese solamente el nombre del archivo.";
        return 1;
    }

    std::ifstream archivo(argv[1]);//Se decide cual archivo txt va a leer!!!

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." <<"\n";
        return 1;
    }
        
    std::string linea;
    std::cout << "Contenido del archivo:" << std::endl;

    while (std::getline(archivo, linea)) {
        std::cout << linea << std::endl;
    }

    archivo.close();

    /*
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
    */
}
