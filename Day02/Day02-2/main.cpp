#include <iostream>
#include <vector>
#include <tuple>
#include <string>

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
        int first, second;
        char letter;
        getline(cin, s);

        auto splitted = split(s, ':', 1);
        password = splitted.second;
        auto splitted2 = split(splitted.first, ' ', 0);
        letter = splitted2.second[0];
        auto splitted3 = split(splitted2.first, '-', 0);
        first = stoi(splitted3.first);
        second = stoi(splitted3.second);

        input.push_back(make_tuple(first, second, letter, password));
    }

    int nValid = 0;

    for (auto t : input) {
        string pass = get<3>(t);
        char letter = get<2>(t);

        int first = get<0>(t), second = get<1>(t);
        if ((pass[first-1] == letter) ^ (pass[second-1] == letter)) {
            nValid++;
        }

    }

    cout << nValid;

    return 0;
}
