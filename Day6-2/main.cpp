#include <iostream>
#include <set>

using namespace std;

int main() {

    int total = 0;
    set<char> answered;
    int nGroup = 0;

    for (int i = 0; i < 2176; i++) {
        string s;
        getline(cin, s);
        if (s == "") { // New group, reset vector
            total += answered.size();
            answered.clear();
            nGroup = 0;
        } else { // New group member, add to total
            if (nGroup == 0) {
                for (char c : s) {
                    answered.insert(c);
                }
            } else {
                set<char> othersAnswered;
                for (char c : s) {
                    othersAnswered.insert(c);
                }

                // Instead of erasing the element in a for loop, we create an aux set and then copy it; much safer
                set<char> aux = answered;
                for (char c : answered) {
                    set<char>::const_iterator it = othersAnswered.find(c);
                    if (it == othersAnswered.end()) { // If not found in the other's set
                        aux.erase(c); // Erase it from the original set
                    }
                }
                answered = aux;
            }
            nGroup++;
        }
    }

    total += answered.size();

    cout << total << endl;

    return 0;
}
