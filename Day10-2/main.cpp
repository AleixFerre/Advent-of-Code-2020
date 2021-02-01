#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

using namespace std;

unsigned long long nConvinacions(set<int>::const_iterator adapter, const set<int>& adapters, vector<unsigned long long>& combinacionsCache) {

    if (*adapter == *adapters.rbegin()) {
        return 1;
    }

    unsigned long long suma = 0;
    unsigned long long minimActual = *adapter;
    adapter++;

    while (adapter != adapters.end() and *adapter - minimActual <= 3) {
        unsigned long long aux = 0;
        if (combinacionsCache[*adapter] == 0) {
            aux = nConvinacions(adapter, adapters, combinacionsCache);
            combinacionsCache[*adapter] = aux;
        } else {
            aux = combinacionsCache[*adapter];
        }
        suma += aux;
        adapter++;
    }

    return suma;
}

int main() {
    set<int> adapters;

    for (int i = 0; i < 94; i++) {
        int n;
        cin >> n;
        adapters.insert(n);
    }
    adapters.insert(0);

    vector<unsigned long long> combinacionsCache(*adapters.rbegin()+1, 0);

    cout << nConvinacions(adapters.begin(), adapters, combinacionsCache) << endl;


    return 0;
}
