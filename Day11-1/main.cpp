#include <iostream>
#include <vector>

using namespace std;

bool estaFueraDeRango(int i, int j, int midaX, int midaY) {
    return i < 0 or j < 0 or i >= midaX or j >= midaY;
}

bool haySitios(const vector<vector<char>>& tauler, int x, int y, int cantidad, char sitio) {
    int nOcupados = 0;

    for (int i = x-1; i <= x+1; i++) {
        for (int j = y-1; j <= y+1; j++) {
            if ((i != x or j != y) and not estaFueraDeRango(i, j, tauler.size(), tauler[i].size())) {
                // Se hace por todos los adyacentes dentro del tablero
                if (tauler[i][j] == sitio) {
                    nOcupados++;
                    if (nOcupados >= cantidad) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int iterateSeats(vector<vector<char>>& tauler) {
    vector<vector<char>> aux = tauler;
    int changed = 0;
    for (unsigned i = 0; i < tauler.size(); i++) {
        for (unsigned j = 0; j < tauler[i].size(); j++) {
            if (tauler[i][j] == 'L') {
                if (not haySitios(tauler, i, j, 1, '#')) {
                    aux[i][j] = '#';
                    changed++;
                }
            } else if (tauler[i][j] == '#') {
                if (haySitios(tauler, i, j, 4, '#')) {
                    aux[i][j] = 'L';
                    changed++;
                }
            }
        }
    }
    tauler = aux;
    return changed;
}

void mostrarTauler(const vector<vector<char>>& tauler) {
    int nOcupados = 0;

    cout << endl
         << "      Tauler" << endl
         << "-------------------" << endl;
    for (unsigned i = 0; i < tauler.size(); i++) {
        for (unsigned j = 0; j < tauler[i].size(); j++) {
            cout << tauler[i][j] << " ";
            if (tauler[i][j] == '#') nOcupados++;
        }
        cout << endl;
    }

    cout << "Ocupados: " << nOcupados << endl;
}

int main() {

    vector<vector<char>> tauler;
    int midaX = 98, midaY = 91;

    for (int i = 0; i < midaX; i++) {
        tauler.push_back(vector<char>());
        for (int j = 0; j < midaY; j++) {
            char c;
            cin >> c;
            tauler[i].push_back(c);
        }
    }

    mostrarTauler(tauler);

    int nChanged, i = 0;
    do {
        nChanged = iterateSeats(tauler);
        i++;
    } while (nChanged != 0);

    mostrarTauler(tauler);
    cout << "En " << i << " iteraciones" << endl;

    return 0;
}
