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

    // We precalculated with the min and max function that the input goes from 15-947 ids
    int minim = 15, maxim = 932;
    vector<bool> ids(maxim, false);

    for (int i = 0; i < maxim; i++) {
        string s;
        cin >> s;
        ids[seatID(s) - minim] = true;
    }

    for (int i = 0; i < maxim; i++) {
        if (not ids[i])
            cout << i + minim << endl;
    }

    return 0;
}

