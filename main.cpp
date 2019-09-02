#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

//#include "stacktrace.h"
#include <cstdlib>
#include "menu.h"
#include "Matriz.h"
#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

int main(int argc, char** argv) {
    if (argc > 4) {


        std::string archivo_entrada(obtener_entrada(argv, argc));
        std::string archivo_salida(obtener_salida(argv, argc));

        if (!archivo_entrada.empty() && !archivo_salida.empty()) {
          
            std::ifstream entrada(archivo_entrada.c_str());
            std::ofstream salida(archivo_salida.c_str());
            std::string linea;
            
            while (std::getline(entrada, linea)) {
                Matriz matriz(linea);
                if (matriz.esMagico()) {
                    std::string str = matriz.toString();
                    salida.write(str.c_str(), str.size());
                }

                linea.clear();
            }

            entrada.close();
            salida.close();

            return EXIT_SUCCESS;
        }


        else {
            std::cerr << std::endl << "Error al determinar las rutas de los archivos de entrada " << archivo_entrada << " y salida " << archivo_salida << std::endl;
            return EXIT_FAILURE;
        }
    } 
    else {
        std::cerr << std::endl << "Argumentos insuficientes" << std::endl;
        std::cerr << std::endl << argv[0] << " -f /ruta/archivo/entrada.txt -o /ruta/archivo/salida.txt" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

