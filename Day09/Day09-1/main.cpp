#include <iostream>
#include <vector>

using namespace std;

bool isValid(int n, const vector<int>& preamble, int previousLen) {

    int start = preamble.size() - previousLen;

    for (unsigned i = start; i < preamble.size(); i++) {
        for (unsigned j = start; j < preamble.size(); j++) {
            if (preamble[i] != preamble[j] and preamble[i] + preamble[j] == n) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<int> preamble;
    int preambleLen = 25, totalLen = 1000;

    for (int i = 0; i < preambleLen; i++) {
        // Preamble
        int n;
        cin >> n;
        preamble.push_back(n);
    }

    for (int i = 0; i < totalLen; i++) {
        // All the numbers
        int n;
        cin >> n;

        if (isValid(n, preamble, preambleLen)) {
            preamble.push_back(n);
        } else {
            cout << n << endl;
            break;
        }
    }

    return 0;
}
