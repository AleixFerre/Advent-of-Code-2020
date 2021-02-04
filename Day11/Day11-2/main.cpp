#include <iostream>
#include <vector>

using namespace std;

bool haySitios(const vector<vector<char>>& tauler, int x, int y, int cantidad, char sitio) {

    const int midaX = tauler.size(), midaY = tauler[0].size();
    int nOcupados = 0;

    // Cap a dalt
    for (int i = x-1; i >= 0; i--) {
        if (tauler[i][y] != '.') {
            if (tauler[i][y] == sitio) {
                nOcupados++;
                if (nOcupados >= cantidad)
                    return true;
            }
            break;
        }
    }

    // Cap a baix
    for (int i = x+1; i < midaY; i++) {
        if (tauler[i][y] != '.') {
            if (tauler[i][y] == sitio) {
                nOcupados++;
                if (nOcupados >= cantidad)
                    return true;
            }
            break;
        }
    }

    // Cap a l'esquerra
    for (int j = y-1; j >= 0; j--) {
        if (tauler[x][j] != '.') {
            if (tauler[x][j] == sitio) {
                nOcupados++;
                if (nOcupados >= cantidad)
                    return true;
            }
            break;
        }
    }

    // Cap a la dreta
    for (int j = y+1; j < midaX; j++) {
        if (tauler[x][j] != '.') {
            if (tauler[x][j] == sitio) {
                nOcupados++;
                if (nOcupados >= cantidad)
                    return true;
            }
            break;
        }
    }

    // Cap a la diagonal dalt-esquerra
    for (int i = -1; x+i >= 0 and y+i >= 0; i--) {
        if (tauler[x+i][y+i] != '.') {
            if (tauler[x+i][y+i] == sitio) {
                nOcupados++;
                if (nOcupados >= cantidad)
                    return true;
            }
            break;
        }
    }

    // Cap a la diagonal dalt-dreta
    for (int i = 1; x+i < midaX and y+i < midaY; i++) {
        if (tauler[x+i][y+i] != '.') {
            if (tauler[x+i][y+i] == sitio) {
                nOcupados++;
                if (nOcupados >= cantidad)
                    return true;
            }
            break;
        }
    }

    // Cap a la diagonal baix-esquerra
    for (int i = 1; x+i < midaX and y-i >= 0; i++) {
        if (tauler[x+i][y-i] != '.') {
            if (tauler[x+i][y-i] == sitio) {
                nOcupados++;
                if (nOcupados >= cantidad)
                    return true;
            }
            break;
        }
    }

    // Cap a la diagonal baix-dreta
    for (int i = 1; x-i >= 0 and y+i < midaY; i++) {
        if (tauler[x-i][y+i] != '.') {
            if (tauler[x-i][y+i] == sitio) {
                nOcupados++;
                if (nOcupados >= cantidad)
                    return true;
            }
            break;
        }
    }

    return false;
}

int iterateSeats(vector<vector<char>>& tauler) {
    vector<vector<char>> aux = tauler;
    int changed = 0;
    for (unsigned i = 0; i < tauler.size(); i++) {
        for (unsigned j = 0; j < tauler[0].size(); j++) {
            if (tauler[i][j] == 'L') {
                if (not haySitios(tauler, i, j, 1, '#')) {
                    aux[i][j] = '#';
                    changed++;
                }
            } else if (tauler[i][j] == '#') {
                if (haySitios(tauler, i, j, 5, '#')) {
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
    //int midaX = 10, midaY = 10;

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
