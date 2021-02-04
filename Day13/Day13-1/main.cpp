#include <iostream>
#include <vector>

using namespace std;

vector<int> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<int> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        if (token != "x")
            res.push_back (stoi(token));
    }
    string sub = s.substr (pos_start);
    if (sub != "x")
        res.push_back (stoi(sub));

    return res;
}

int main() {
    int timeStamp;
    cin >> timeStamp;
    cin.ignore();
    string s;
    getline(cin, s);
    vector<int> buses = split(s, ",");

    bool trobat = false;
    int idBus = -1;
    int demora = 0;
    while (not trobat) {
        for (int bus : buses) {
            if ((timeStamp+demora)%bus == 0) {
                trobat = true;
                idBus = bus;
                break;
            }
        }
        demora++;
    }

    demora--;

    cout << "Demora: " << demora << " | ID: " << idBus << endl;
    cout << "Final: " << demora*idBus << endl;

    return 0;
}
