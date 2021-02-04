#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> input;

    // Read the input file
    for (int i = 0; i < 200; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }

    for (int i : input) {
        for (int j : input) {
            if (i + j == 2020) {
                cout << i * j << endl;
            }
        }
    }

    return 0;
}
