#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<string> input;

    for (int i = 0; i < 323; i++) {
        string s;
        cin >> s;
        input.push_back(s);
    }

    int nTrees = 0, x = 0, y = 0, len = input[0].size();

    while (x < (int)input.size()) {
        if (input[x][y % len] == '#')
            nTrees++;
        x++;
        y+=3;
    }


    cout << nTrees;

    return 0;
}
