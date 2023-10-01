//Comando para compilar: g++ -std=c++11 main.cpp -o prueba
//Comando para ejecutar: ./prueba
//#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include "ArbolQuad.h"
 
int main(int argc, char *argv[]){
    std::string nombre_archivo_lectura;
    std::string cinUsuario;

    if (argc < 2) {
        std::cout << "Ingresea el nombre del archivo." << std::endl;
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
    std::cout << "Contenido del archivo:\n";


    if (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        int numero1, numero2;

        if (iss >> numero1 >> numero2) {
            std::cout<<"---------Dimension---------\n";
            std::cout<<numero1<<"x"<<numero2<<"\n";
            std::cout<<"---------Dimension---------\n";
        } else {
            std::cerr << "La primera línea no contiene dos números válidos.\n";
            return 1;
        }
    }else {
        std::cerr << "El archivo está vacío.\n";
        return 1;
    }

    std::cout<<"\n---------Restante---------\n";
    while (std::getline(archivo, linea)) {
        std::cout << linea << std::endl;

        char primerCaracter = linea[0];
        int numero = primerCaracter - '0';
        ArbolQuad arbol(numero);

        for(int i = 1; i < linea.length(); i++) {
            primerCaracter = linea[i];
            numero = primerCaracter - '0';
            arbol.insertarNodo(numero);
        }
        std::cout << std::endl << "Preorden: ";
        arbol.preOrden();
    }
    std::cout<<"\n---------Restante---------\n";

    archivo.close();
}
