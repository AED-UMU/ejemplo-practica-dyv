#include <iostream>
#include <cassert>
#include "dyv.h"

void testPrincipio() {
    std::vector<int> S = {1, 2, 3, 2, 3, 4, 1, 2};
    assert(busquedaDyV(S, 0, S.size() - 1, 1));
}

void testFinal() {
    std::vector<int> S = {1, 2, 3, 2, 3, 4, 1, 2, 1, 2, 3, 4};
    assert(busquedaDyV(S, 0, S.size() - 1, 4));
}

void testMitad() {
    std::vector<int> S = {1, 2, 3, 4, 1, 2, 3, 4, 5, 6, 1, 2, 3, 4};
    assert(busquedaDyV(S, 0, S.size() - 1, 3));
}

void testNoEsta() {
    std::vector<int> S = {5, 4, 3, 2, 1};
    assert(!busquedaDyV(S, 0, S.size() - 1, 6));
}
int main() {
    testPrincipio();
    testMitad();
    testFinal();
    testNoEsta();
    std::cout << "Todos los tests pasaron!" << std::endl;
    return 0;
}