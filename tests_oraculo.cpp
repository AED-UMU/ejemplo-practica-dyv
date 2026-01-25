#include <iostream>
#include "dyv.h"
#include <cassert>
#include <random>

using namespace std;


vector<int> generarSecuenciaAleatoria(int longitud, int minimo, int maximo, unsigned int semilla) {
    vector<int> secuencia(longitud);

    mt19937 gen(semilla);
    uniform_int_distribution<> dist(minimo, maximo);

    for (int i = 0; i < longitud; ++i) {
        secuencia[i] = dist(gen);
    }

    return secuencia;
}


int main() {
    unsigned int semilla = 42;
    int minimo = 0;
    int maximo = 100;

    vector<int> longitudes = {5, 10, 20, 50, 100, 1000};

    for (size_t i = 0; i < longitudes.size(); ++i) {
        int longitud = longitudes[i];
        vector<int> secuencia = generarSecuenciaAleatoria(longitud, minimo, maximo, semilla + i);

        for (int val : secuencia) {
            bool dyvOutput = busquedaDyV(secuencia, 0, secuencia.size() - 1, val);
            bool resultadoIterativo = busquedaIterativo(secuencia, val);
            assert(dyvOutput == resultadoIterativo);
        }
        
        int valorNoPresente = maximo + 1;
        bool dyvOutput = busquedaDyV(secuencia, 0, secuencia.size() - 1, valorNoPresente);
        bool resultadoIterativo = busquedaIterativo(secuencia, valorNoPresente);
        assert(dyvOutput == resultadoIterativo);
        
        cout << "Longitud de la secuencia: " << longitud << endl;
        cout << "Test de búsqueda completado exitosamente." << endl;
    }

    return 0;
}