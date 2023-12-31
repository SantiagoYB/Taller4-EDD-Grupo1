//Comando para compilar: g++ -std=c++11 main.cpp -o prueba
//Comando para ejecutar: ./prueba
#include <iostream>
#include <fstream>
#include <sstream>
#include "ArbolQuad.h"
 
int main(int argc, char *argv[]){
    std::string nombre_archivo_lectura, nombre_archivo_salida;
    std::string cinUsuario;

    if (argc != 3) {
        std::cerr << "Para ejecutar el programa inicielo de la siguiente manera: \nnombre_programa <imagen_de_entrada.qt> <archivo_de_salida.pbm>" << std::endl;
        return 1;
    }

    // Verificar archivo de entrada y salida
    for (int i = 1; i < argc; i++) {
        std::string valor = argv[i];

        if (valor.length() >= 3 && valor.substr(valor.length() - 3) == ".qt") {
            //Verifica la extension
            nombre_archivo_lectura = valor;
        } 
        else if (valor.length() >= 4 && valor.substr(valor.length() - 4) == ".pbm") {
            //Verifica la extension
            nombre_archivo_salida = valor;
        } 
        else {
            std::cerr << "Para ejecutar el programa inicielo de la siguiente manera: \nnombre_programa <imagen_de_entrada.qt> <archivo_de_salida.pbm>" << std::endl;
            return 1;
        }
    }

    //Se decide cual archivo txt va a leer!!!
    std::ifstream archivo(nombre_archivo_lectura);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." <<"\n";
        return 1;
    }

    std::string linea;
    std::cout << "Contenido del archivo:\n";

    int numero1, numero2;
    if (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        

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
        std::cout<<"\n---------Restante---------\n";
        std::cout << std::endl << "Preorden: ";
        arbol.preOrden();

        int** matriz = arbol.llenarMatriz(arbol.crearMatriz(numero1), arbol.obtenerRaiz(), 0, 0, numero1);

        std::ofstream archivo(nombre_archivo_salida);
        archivo << "P1\n";
        archivo << "# Imagen: "+nombre_archivo_lectura+"\n";
        archivo << numero1 << " " << numero2 << "\n";
        for(int i = 0; i < numero1; i++) {
            for(int j = 0; j < numero2; j++) {
                archivo << matriz[i][j];
            }
            archivo << "\n";
        } 
    }
    archivo.close();
    std::cout << std::endl << "Se ha creado el archivo " << nombre_archivo_salida << std::endl;
}






