#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Bag {
  public:
    Bag();
    Bag(const string& s);

    void addDependency(const pair<string,string>& p, int amount);

    bool canHaveBag(const pair<string,string>& colors, const map<pair<string,string>, Bag>& bags) const;

    int getNumOfOtherBags(const map<pair<string,string>, Bag>& bags, int startCounter) const;

    pair<string, string> getColors() const;

  private:
    pair<string,string> colors;
    map<pair<string,string>, int> dependencies;

    vector<string> split(const string& str, char delimiter) const;
};

#endif // BAG_H
