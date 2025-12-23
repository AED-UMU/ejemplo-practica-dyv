#include <iostream>
#include "dyv.h"
#include <cassert>
#include <math.h>
#include <fstream>
#include <chrono>
#include <algorithm>

using namespace std;


vector<int> generarPeorCaso(int longitud) {
    vector<int> secuencia(longitud);
    for (int i = 0; i < longitud; ++i) {
        secuencia[i] = i;
    }
    return secuencia;
}

vector<int> generarMejorCaso(int longitud) {
    vector<int> secuencia(longitud);
    for (int i = 0; i < longitud; ++i) {
        secuencia[i] = longitud - i;
    }
    return secuencia;
}


// Mide el tiempo que tarda la función en ejecutarse
double medirTiempo(const std::vector<int>& secuencia) {
    auto start = std::chrono::high_resolution_clock::now();

    int resultado = subsecuenciaMasLargaDyV(secuencia, 0, secuencia.size() - 1);  // Usa tu versión iterativa

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracion = end - start;
    return duracion.count();
}

double mediana(std::vector<double> v) {
    int n = v.size();
    if (n == 0) return 0.0;

    std::sort(v.begin(), v.end());

    if (n % 2 == 1)
        return v[n / 2];
    else
        return (v[n / 2 - 1] + v[n / 2]) / 2.0;
}

int main() {
    std::vector<int> longitudes;
    for (int i = 0; i <= 10; i += 1) {
        longitudes.push_back(1000 * pow(2, i));
    }
    std::ofstream csv("resultados.csv");
    csv << "Longitud,MejorCaso,PeorCaso\n";

    for (int longitud : longitudes) {
        auto mejorCaso = generarMejorCaso(longitud);
        vector<double> mejoresCasos;
        for (int j = 0; j < 10; j += 1){
            auto mejorTiempo = medirTiempo(mejorCaso);
            mejoresCasos.push_back(mejorTiempo);
        }
        auto medianaMejorTiempo = mediana(mejoresCasos);
        

        auto peorCaso = generarPeorCaso(longitud);
        vector<double> peoresCasos;
        for (int j = 0; j < 10; j += 1){
            auto peorTiempo = medirTiempo(peorCaso);
            peoresCasos.push_back(peorTiempo);
        }
        auto medianaPeorTiempo = mediana(peoresCasos);
        
        csv << longitud << "," << medianaMejorTiempo << "," << medianaPeorTiempo << "\n";
    }

    csv.close();
    return 0;
}
