#include <vector>

using namespace std;

bool pequeno(int p, int q) {
    return p == q;
}

int solucionPequena(const vector<int>& S, int p, int q, int v) {
    return S[p] == v;
}

bool busquedaDyV(const vector<int>& S, int p, int q, int v) {
    if (pequeno(p, q)) {
        return solucionPequena(S, p, q, v);
    }

    int m = (p + q) / 2;
    bool izq = busquedaDyV(S, p, m, v);

    if (izq) {
        return true;
    }

    bool der = busquedaDyV(S, m + 1, q, v);
    
    if (der) {
        return true;
    }
    return false;
}

bool busquedaIterativo(const std::vector<int>& S, int v) {
    for (size_t i = 0; i < S.size(); ++i) {
        if (S[i] == v) {
            return true;
        }
    }
    return false;
}
