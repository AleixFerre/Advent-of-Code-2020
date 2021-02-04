#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int binarySearch(const string& v, const char lowerHalfChar) {

    int low = 0, high = pow(2, v.size()), mid = (low+high)/2, index = 0;

    while (low < high) {
        if (v[index] == lowerHalfChar) { // Lower half
            high = mid;
        } else { // Upper half
            low = mid;
        }
        index++;
        mid = (low+high)/2;
    }

    if (mid == low)
        return mid;
    else
        return mid+1;
}

int seatID(const string& s) {
    string rows = s.substr(0, 7), cols = s.substr(7, 10);
    return binarySearch(rows, 'F') * 8 + binarySearch(cols, 'L');
}

int main() {

    vector<string> input;
    int maximum = 0;

    for (int i = 0; i < 932; i++) {
        string s;
        cin >> s;
        input.push_back(s);
    }

    for (string s : input) {
        int id = seatID(s);
        if (id > maximum) {
            maximum = id;
        }
    }

    cout << maximum << endl;

    return 0;
}
