#include <iostream>
#include <cstring>
using namespace std;
 
#define INT_MAX         2147483647
 
int dp[22][4];
int cost[22][4];
int n;
 
void init()
{
    memset(dp, -1, sizeof(dp));
}
 
int min(int a, int b)
{
    if (a <= b)
        return a;
    return b;
}
 
int solve(int house, int color)
{
    if (house > n)
        return 0;
    if (dp[house][color] != -1)
        return dp[house][color];
 
    int mini = INT_MAX;
    for (int i = 1; i <= 3; i++){
        if (i == color)
            continue;
        mini = min(mini, cost[house][i] + solve(house + 1, i));
    }
    return dp[house][color] = mini;
}
 
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; testCase++){
        cin >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= 3; j++){
                cin >> cost[i][j];
            }
        }
        init();
        int mini = INT_MAX;
        for (int i = 1; i <= 3; i++){
            mini = min(mini, cost[1][i] + solve(1+1, i));
        }
        cout << "Case " << testCase << ": " << mini << endl;
    }
 
 
 
    return 0;
}