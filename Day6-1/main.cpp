#include <iostream>
#include <vector>

using namespace std;

int main() {

    int total = 0;
    vector<bool> answered('z' - 'a', false);

    for (int i = 0; i < 2176; i++) {
        string s;
        getline(cin, s);
        if (s == "") { // New group, reset vector
            answered = vector<bool>('z' - 'a', false);
        } else { // New group member, add to total
            for (char c : s) {
                if (not answered[c - 'a']) {
                    total++;
                    answered[c - 'a'] = true;
                }
            }
        }
    }

    cout << total << endl;

    return 0;
}
