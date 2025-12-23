#include <iostream>
#include <cassert>
#include "dyv.h"

void testPrincipio() {
    std::vector<int> S = {1, 2, 3, 2, 3, 4, 1, 2};
    int resultado = subsecuenciaMasLargaDyV(S, 0, S.size() - 1);
    assert(resultado == 3); 
}

void testFinal() {
    std::vector<int> S = {1, 2, 3, 2, 3, 4, 1, 2, 1, 2, 3, 4};
    int resultado = subsecuenciaMasLargaDyV(S, 0, S.size() - 1);
    assert(resultado == 4); 
}

void testMitad() {
    std::vector<int> S = {1, 2, 3, 4, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4};
    int resultado = subsecuenciaMasLargaDyV(S, 0, S.size() - 1);
    assert(resultado == 6);
}

void testDecreciente() {
    std::vector<int> S = {5, 4, 3, 2, 1};
    int resultado = subsecuenciaMasLargaDyV(S, 0, S.size() - 1);
    assert(resultado == 1); 
}

void testCreciente() {
    std::vector<int> S = {1, 2, 3, 4, 5};
    int resultado = subsecuenciaMasLargaDyV(S, 0, S.size() - 1);
    assert(resultado == 5); 
}

int main() {
    testPrincipio();
    testMitad();
    testFinal();
    testDecreciente();
    testCreciente();
    std::cout << "Todos los tests pasaron!" << std::endl;
    return 0;
}