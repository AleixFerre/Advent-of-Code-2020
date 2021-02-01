#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> adapters;

    for (int i = 0; i < 94; i++) {
        int n;
        cin >> n;
        adapters.insert(n);
    }

    int prev = 0, n1 = 0, n3 = 1;
    for (int adapter : adapters) {
        if (adapter - prev == 1) n1++;
        if (adapter - prev == 3) n3++;
        prev = adapter;
    }

    cout << endl << n1 << endl << n3 << endl;
    cout << n1 * n3 << endl;

    return 0;
}
