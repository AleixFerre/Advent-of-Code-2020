#include "Bag.h"

using namespace std;

int main() {

    map<pair<string,string>, Bag> bags;
    int total = 0;

    for (int i = 0; i < 594; i++) {
        string s;
        getline(cin, s);
        Bag b(s);
        bags.insert(make_pair(b.getColors(), b));
    }

    // When I have all the map entered, we search for shiny gold bags

    for (auto it : bags) {
        if (it.second.canHaveBag(make_pair("shiny", "gold"), bags)) {
            total++;
        }
    }

    cout << total << endl;

    return 0;
}
