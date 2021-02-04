#include <iostream>
#include <map>

using namespace std;

map<int, int> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    map<int, int> res;
    int i = 0;
    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        if (token != "x")
            res.insert(make_pair(stoi(token), i));
        i++;
    }
    string sub = s.substr (pos_start);
    if (sub != "x") {
        res.insert(make_pair(stoi(sub), i));
    }

    return res;
}

bool surt(int bus, const unsigned long long& timeStamp) {
    return timeStamp % bus == 0;
}

int main() {
    unsigned long long timeStamp;
    cin >> timeStamp;
    timeStamp = 0;
    cin.ignore();
    string s;
    getline(cin, s);
    map<int, int> buses = split(s, ",");

    bool trobat = false;

    for (pair<int,int> bus : buses) {
        cout << bus.first << " " << bus.second << endl;
    }

    return 0;


    while (not trobat) {
        bool valid = true;
        for (pair<int,int> bus : buses) {
            if (not surt(bus.second, bus.first + timeStamp)) {
                valid = false;
                break;
            }
        }
        if (valid) break;
        timeStamp++;
    }

    cout << timeStamp << endl;

    return 0;
}
