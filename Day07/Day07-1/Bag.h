#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Bag {
  public:
    Bag();
    Bag(const string& s);

    void addDependency(const pair<string,string>& p);

    bool canHaveBag(const pair<string,string>& colors, const map<pair<string,string>, Bag>& bags) const;

    pair<string, string> getColors() const;

  private:
    pair<string,string> colors;
    set<pair<string,string>> dependencies;

    vector<string> split(const string& str, char delimiter) const;

};

#endif // BAG_H
