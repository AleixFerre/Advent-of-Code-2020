#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <stdlib.h>

using namespace std;

pair<string,string> split(string s, char delim, int deletedChars) {
    string l = "", r = "";
    unsigned index = 0;
    char actual = s[index];
    while (actual != delim or index >= s.size()) {
        l += actual;
        index++;
        actual = s[index];
    }

    index += 1 + deletedChars; // Throw the delim and the space to the trash

    while (index < s.size()) {
        actual = s[index];
        r += actual;
        index++;
    }

    return pair<string, string>(l, r);
}


int main() {

    vector<tuple<int,int,char,string>> input;

    // Read the input file
    for (int i = 0; i < 1000; i++) {
        string s, password;
        int minimum, maximum;
        char letter;
        getline(cin, s);

        auto splitted = split(s, ':', 1);
        password = splitted.second;
        auto splitted2 = split(splitted.first, ' ', 0);
        letter = splitted2.second[0];
        auto splitted3 = split(splitted2.first, '-', 0);
        minimum = stoi(splitted3.first);
        maximum = stoi(splitted3.second);

        input.push_back(make_tuple(minimum, maximum, letter, password));
    }

    int nValid = 0;

    for (auto t : input) {
        int nTimes = 0;
        string pass = get<3>(t);
        char letter = get<2>(t);
        for (unsigned i = 0; i < pass.size(); i++) {
            if (pass[i] == letter) {
                nTimes++;
            }
        }

        int minimum = get<0>(t), maximum = get<1>(t);
        if (nTimes >= minimum and nTimes <= maximum) {
            nValid++;
        }

    }

    cout << nValid;

    return 0;
}
