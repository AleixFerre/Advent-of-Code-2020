#include <iostream>
#include <vector>

using namespace std;

int runCommand(const vector<pair<string,int>>& commands) {

    vector<bool> visited (commands.size(), false);
    int index = 0, accumulator = 0;

    while (index < (int)commands.size()) { // While don't reach final
        if (visited[index]) { // If cannot reach final (so we have an infinite loop)
            throw "NOPE"; // Throw an exception to say "not this one"
            // I can actually return -1, but if accumulator is actually -1? We have a problem...
            // In C++ returning NULL is not recommended at all; and I cannot pronounce undefined :O
        }

        // Otherwise...

        visited[index] = true; // Check visited of the actual index to true

        string com = commands[index].first;
        int param = commands[index].second;

        if (com == "nop") { // Execute the respective commands
            index++;
        } else if (com == "acc") {
            accumulator += param;
            index++;
        } else if (com == "jmp") {
            index += param;
        }
    }

    return accumulator; // If we reach final, we can now see the accumulator
}

int main() {
    int len = 638;
    vector<pair<string,int>> commands;


    for (int i = 0; i < len; i++) { // Read the input
        string com;
        int param;
        cin >> com >> param;
        commands.push_back(make_pair(com, param));
    }

    for (int i = 0; i < len; i++) { // For every command
        if (commands[i].first != "acc") {
            string newOperation = commands[i].first == "nop" ? "jmp" : "nop";
            vector<pair<string, int>> newCommands = commands; // We create a new copy with the modification
            newCommands[i].first = newOperation;
            try {
                int acc = runCommand(newCommands); // Can reach final?
                cout << acc << endl; // Check it out
            } catch (const char* err) { }
        }
    }

    return 0;
}
