#include "Bag.h"
#include <sstream>

Bag::Bag() {
    colors.first = colors.second = "No color";
}

Bag::Bag(const string& s) {

    vector<string> splitted = split(s, ' ');

    colors.first = splitted[0];
    colors.second = splitted[1];

    // Ignore words: "bags" "contain" (+2 indices)

    if (splitted[4] != "no") { // Assuming "other" and "bags", it has no more bags, so we return; otherwise...
        // We can actually ignore how many we have, we need at least one
        int amount = stoi(splitted[4]);
        addDependency(make_pair(splitted[5], splitted[6]), amount);
        int index = 7;
        while (splitted[index].back() == ',') {
            amount = stoi(splitted[1+index]);
            addDependency(make_pair(splitted[2+index], splitted[3+index]), amount);
            index += 4;
        }
    }
}

void Bag::addDependency(const pair<string,string>& p, int amount) {
    dependencies.insert(make_pair(p, amount));
}

pair<string, string> Bag::getColors() const {
    return colors;
}

bool Bag::canHaveBag(const pair<string, string>& colors, const map<pair<string,string>, Bag>& bags) const {
    if (dependencies.find(colors) != dependencies.end()) {
        // Found!
        return true;
    } else {
        // Not found in this bag, find in the other dependent bags instead
        for (auto p : dependencies) {
            if (bags.at(p.first).canHaveBag(colors, bags)) {
                return true;
            }
        }
        return false;
    }
}

int Bag::getNumOfOtherBags(const map<pair<string, string>, Bag>& bags, int startCounter) const {
    int total = startCounter;

    for (auto p : dependencies) {
        total += p.second * bags.at(p.first).getNumOfOtherBags(bags, 1);
    }

    return total;
}

vector<string> Bag::split(const string& str, char delimiter) const {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}
