#include <iostream>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);

    int testCase;
    cin >> testCase;
    cin.ignore();
    while (testCase--) {
        string s;
        char c;

        getline(cin, s);
        cin >> c;
        cin.ignore();

        int len = s.size();
        bool result = false;
        for (int i = 0; i < len; i++) {
            if (s[i] == c) {
                if (i % 2 == 0 && (len - (i + 1)) % 2 == 0) {
                    result = true;
                    break;
                }
            }
        }

        if (result) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
