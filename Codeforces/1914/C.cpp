#include <iostream>
#include <sstream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc, n, k;
    string line;

    getline(cin, line);
    tc = stoi(line);

    while (tc--) {
        getline(cin, line);
        stringstream ss(line, ios::out | ios::in);
        ss >> n >> k;

        vector<int> a = vector<int>(n + 1, 0);
        vector<int> b = vector<int>(n + 1, 0);

        getline(cin, line);
        ss.clear();
        ss.str(line);

        int reward;
        for (int i = 1; i <= n; ++i) {
            ss >> a[i];
            a[i] += a[i-1];
        }

        getline(cin, line);
        ss.clear();
        ss.str(line);

        for (int i = 1; i <= n; ++i) {
            ss >> b[i];
            b[i] = max(b[i], b[i-1]);
        }

        int maxi = INT_MIN;
        for (int i = 1; i <= n; ++i) {
            if (k >= i) maxi = max(maxi, a[i] + b[i] * (k-i));
        }

        cout << maxi << endl;

    }

    return 0;
}
