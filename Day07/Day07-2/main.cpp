#include "Bag.h"

using namespace std;

int main() {

    map<pair<string,string>, Bag> bags;

    for (int i = 0; i < 594; i++) {
        string s;
        getline(cin, s);
        Bag b(s);
        bags.insert(make_pair(b.getColors(), b));
    }

    // When I have all the map entered, we search for shiny gold bags

    cout << bags.at(make_pair("shiny", "gold")).getNumOfOtherBags(bags, 0) << endl;

    return 0;
}
