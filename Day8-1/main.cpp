#include <iostream>
#include <vector>

using namespace std;

int main() {
    int accumulator = 0, index = 0;
    int len = 638;
    vector<bool> visited (len, false);
    vector<pair<string,int>> commands;

    for (int i = 0; i < len; i++) {
        string com;
        int param;
        cin >> com >> param;
        commands.push_back(make_pair(com, param));
    }

    while (not visited[index]) {
        visited[index] = true;

        // Process the current index
        string com = commands[index].first;
        int param = commands[index].second;
        if (com == "nop") {
            index++;
        } else if (com == "acc") {
            accumulator += param;
            index++;
        } else if (com == "jmp") {
            index += param;
        }
    }

    cout << accumulator << endl;
    return 0;
}
