#include <iostream>
#include <unordered_map>
#include <string.h>

using namespace std;

int main() {

    freopen("input.txt", "r", stdin);

    int tc, n;
    string logs, line;
    unordered_map<char, int> hashMap;

    getline(cin, line);
    tc = stoi(line);

    while (tc--) {
        getline(cin, line);
        getline(cin, logs);

        n = stoi(line);

        hashMap.clear();
        for (int i = 0; i < logs.size(); ++i) {
            hashMap[logs[i]]++;
        }

        int count = 0;
        for (char ch = 'A'; ch <= 'Z'; ++ch) {
            if (hashMap[ch] >= (ch - 'A' + 1)) count++;
        }

        cout << count << endl;

    }

    return 0;
}
