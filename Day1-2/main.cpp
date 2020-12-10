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
            for (int k : input) {
                if (i + j + k == 2020) {
                    cout << i * j * k << endl;
                }
            }
        }
    }

    return 0;
}
