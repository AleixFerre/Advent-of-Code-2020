#include <iostream>
#include <vector>

using namespace std;

unsigned trees(unsigned incX, unsigned incY, unsigned lenX, unsigned lenY, const vector<string>& input) {
    unsigned nTrees = 0, x = 0, y = 0;

    while (y < lenY) {
        if (input[y][x % lenX] == '#')
            nTrees++;
        x += incX;
        y += incY;
    }

    return nTrees;
}

int main() {

    vector<string> input;

    for (unsigned i = 0; i < 323; i++) {
        string s;
        cin >> s;
        input.push_back(s);
    }

    unsigned lenX = input[0].size(), lenY = input.size();

    unsigned res = trees(1, 1, lenX, lenY, input) *
              trees(3, 1, lenX, lenY, input) *
              trees(5, 1, lenX, lenY, input) *
              trees(7, 1, lenX, lenY, input) *
              trees(1, 2, lenX, lenY, input);

    cout << res;

    return 0;
}
