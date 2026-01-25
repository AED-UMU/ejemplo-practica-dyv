#include <iostream>
#include "dyv.h"
#include <cassert>
#include <math.h>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <utility>

using namespace std;


pair<vector<int>, int> generarPeorCaso(int longitud) {
    vector<int> secuencia(longitud);
    for (int i = 0; i < longitud; ++i) {
        secuencia[i] = i;
    }
    return pair<vector<int>, int>(secuencia, longitud + 1); // Valor que no está en la secuencia
}

pair<vector<int>, int> generarMejorCaso(int longitud) {
    vector<int> secuencia(longitud);
    for (int i = 0; i < longitud; ++i) {
        secuencia[i] = i;
    }
    return pair<vector<int>, int>(secuencia, secuencia[0]); // Valor que está al inicio de la secuencia
}

#include <x86intrin.h>   // __rdtsc
#include <immintrin.h>   // _mm_lfence

volatile bool sink; // evita optimización

// mide mendiante ciclos de CPU
unsigned long long medirCiclos(const std::vector<int>& secuencia, int valorBuscado) {
    _mm_lfence(); // serializa
    unsigned long long start = __rdtsc();
    _mm_lfence();

    sink = busquedaDyV(secuencia, 0, secuencia.size() - 1, valorBuscado);

    _mm_lfence();
    unsigned long long end = __rdtsc();
    _mm_lfence();

    return end - start; // ciclos CPU
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
    std::ofstream csv("resultados_peor_caso.csv");
    csv << "Longitud,PeorCaso\n";

    for (int longitud : longitudes) {
        auto peorCaso = generarPeorCaso(longitud);
        vector<double> peoresCasos;
        for (int j = 0; j < 10; j += 1){
            auto peorTiempo = medirCiclos(peorCaso.first, peorCaso.second);
            peoresCasos.push_back(peorTiempo);
        }
        auto medianaPeorTiempo = mediana(peoresCasos);
        
        csv << longitud << "," << medianaPeorTiempo << "\n";
    }

    csv.close();

    // Idem pero para el mejor caso
    std::ofstream csv_mejor("resultados_mejor_caso.csv");
    csv_mejor << "Longitud,MejorCaso\n";
    longitudes.clear();
    for (int i = 5; i <= 20; i += 1) {
        longitudes.push_back(1000 * pow(2, i));
    }

    for (int longitud : longitudes) {
        auto mejorCaso = generarMejorCaso(longitud);
        vector<double> mejoresCasos;
        for (int j = 0; j < 10; j += 1){
            auto mejorTiempo = medirCiclos(mejorCaso.first, mejorCaso.second);
            mejoresCasos.push_back(mejorTiempo);
        }
        auto medianaMejorTiempo = mediana(mejoresCasos);
        
        csv_mejor << longitud << "," << medianaMejorTiempo << "\n";
    }
    csv_mejor.close();

    return 0;
}
