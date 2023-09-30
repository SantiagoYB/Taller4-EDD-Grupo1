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
}
