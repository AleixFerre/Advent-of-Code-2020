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

int main() {

    vector<string> input;
    int total = 0;

    for (int i = 0; i < 1169; i++) {
        string s;
        getline(cin, s);
        input.push_back(s);
    }

    int credentials = 0;
    bool hasCid = false;
    for (string s : input) {
        if (s == "") { // New passport
            if ((hasCid and credentials == 8) or (not hasCid and credentials == 7)) {
                total++;
            }
            credentials = 0;
            hasCid = false;
        } else { // Process line
            vector<string> creds = split(s.c_str());
            credentials += creds.size();
            for (string cred : creds) {
                vector<string> c = split(cred.c_str(), ':');
                if (c[0] == "cid") {
                    hasCid = true;
                    break; // No need for more search, we have the info
                }
            }
        }
    }

    // Process the last one
    if ((hasCid and credentials == 8) or (not hasCid and credentials == 7)) {
        total++;
    }

    cout << total << endl;

    return 0;
}
