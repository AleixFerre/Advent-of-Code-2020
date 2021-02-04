#include <iostream>
#include <vector>

using namespace std;

vector<string> split(const char* str, char c = ' ') {
    vector<string> result;

    do {
        const char *b = str;

        while(*str != c && *str)
            str++;

        result.push_back(string(b, str));
    } while (0 != *str++);

    return result;
}

bool checkByr(const string& s) {
    if (s.size() != 4)
        return false;

    for (char c : s)
        if (not isdigit(c))
            return false;

    int num = stoi(s);
    return num >= 1920 and num <= 2002;
}

bool checkIyr(const string& s) {
    if (s.size() != 4)
        return false;

    for (char c : s)
        if (not isdigit(c))
            return false;

    int num = stoi(s);
    return num >= 2010 and num <= 2020;
}

bool checkEyr(const string& s) {
    if (s.size() != 4)
        return false;

    for (char c : s)
        if (not isdigit(c))
            return false;

    int num = stoi(s);
    return num >= 2020 and num <= 2030;
}

bool checkHgt(const string& s) {
    if (s.size() == 0)
        return false;

    string snum = "", units = "";
    int index = 0;
    char c = s[index];
    while (isdigit(c) and index < (int)s.size()) {
        snum += c;
        index++;
        c = s[index];
    }

    while (index < (int)s.size()) {
        units += c;
        index++;
        c = s[index];
    }

    if (snum.size() == 0 or units.size() == 0)
        return false;

    if (units == "cm") {
        int num = stoi(snum);
        return num >= 150 and num <= 193;
    } else if (units == "in") {
        int num = stoi(snum);
        return num >= 59 and num <= 76;
    } else {
        return false;
    }
}

bool checkHcl(const string& s) {
    if (s.size() != 7)
        return false;

    if (s[0] != '#')
        return false;

    for (unsigned i = 1; i < s.size(); i++) {
        if (not (isdigit(s[i]) or (s[i] >= 'a' and  s[i] <= 'f')))
            return false;
    }

    return true;
}

bool checkEcl(const string& s) {
    return s == "amb" or
           s == "blu" or
           s == "brn" or
           s == "gry" or
           s == "grn" or
           s == "hzl" or
           s == "oth";
}

bool checkPid(const string& s) {
    if (s.size() != 9)
        return false;

    for (char c : s)
        if (not isdigit(c))
            return false;

    return true;
}

int main() {

    vector<string> input;
    int total = 0;

    for (int i = 0; i < 1169; i++) {
        string s;
        getline(cin, s);
        input.push_back(s);
    }

    int credentials = 0;
    bool hasCid = false, valid = true;
    for (string s : input) {
        if (s == "" or not valid) { // New passport
            if (valid and ((hasCid and credentials == 8) or (not hasCid and credentials == 7))) {
                total++;
            }
            credentials = 0;
            hasCid = false;
            valid = true;
        } else { // Process line
            vector<string> creds = split(s.c_str());
            credentials += creds.size();
            for (string cred : creds) {
                vector<string> c = split(cred.c_str(), ':');
                if (c[0] == "cid") {
                    hasCid = true;
                } else if (c[0] == "byr") {
                    valid = checkByr(c[1]);
                } else if (c[0] == "iyr") {
                    valid = checkIyr(c[1]);
                } else if (c[0] == "eyr") {
                    valid = checkEyr(c[1]);
                } else if (c[0] == "hgt") {
                    valid = checkHgt(c[1]);
                } else if (c[0] == "hcl") {
                    valid = checkHcl(c[1]);
                } else if (c[0] == "ecl") {
                    valid = checkEcl(c[1]);
                } else if (c[0] == "pid") {
                    valid = checkPid(c[1]);
                }

                if (not valid)
                    break; // Not valid, break the inner loop, no more checks
            }
        }
    }

    // Process the last one
    if (valid and ((hasCid and credentials == 8) or (not hasCid and credentials == 7))) {
        total++;
    }

    cout << total << endl;

    return 0;
}
