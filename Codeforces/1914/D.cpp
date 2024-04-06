#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>

using namespace std;

static const int MAX_N = 100000;
static const int MAX_CHOICE = 3;
static const int BASE = 2;
static const int MAX_MASK = pow(BASE, MAX_CHOICE) - 1;
static const int MAX_FRIEND = 100000000;
static const int INF = - (MAX_CHOICE * MAX_FRIEND);

int dp[MAX_N + 1][MAX_MASK + 1];

int getMaximumFriends(int index, int n, int mask, vector<int> a[]) {
    if (index >= n) {
        if (mask == MAX_MASK) return 0;

        return INF;
    }

    if (dp[index][mask] != -1) {
        return dp[index][mask];
    }

    int maxi = getMaximumFriends(index + 1, n, mask, a);
    for (int i = 0; i < MAX_CHOICE; ++i) {
        if ((mask & (1 << i)) == 0) {
            maxi = max(maxi, a[i][index] + getMaximumFriends(index + 1, n, mask | (1 << i), a));
        }
    }

    return dp[index][mask] = maxi;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc, n;

    cin >> tc;

    while (tc--) {
        cin >> n;
        vector<int> a[MAX_CHOICE];

        int num;
        for (int i = 0; i < MAX_CHOICE; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> num;
                a[i].emplace_back(num);
            }
        }

        memset(dp, -1, sizeof(dp));
        cout << getMaximumFriends(0, n, 0, a) << endl;
    }

    return 0;
}
