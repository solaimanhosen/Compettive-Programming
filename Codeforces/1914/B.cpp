#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    int tc, n, k;
    string line;

    getline(cin, line);
    tc = stoi(line);

    while (tc--) {
        cin >> n >> k;

        vector<int> problemList = vector<int>();
        for (int i = 1; i <= k; ++i) {
            problemList.emplace_back(i);
        }

        for (int i = n; i >= k + 1; --i) {
            problemList.emplace_back(i);
        }

        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << " ";
            cout << problemList[i];
        }
        cout << endl;
    }

    return 0;
}
