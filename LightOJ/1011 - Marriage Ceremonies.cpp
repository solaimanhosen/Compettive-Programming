#include <iostream>
#include <cstring>
 
using namespace std;
 
#define N           16
 
int affinity[N+1][N+1];
int dp[N+1][(1 << N)+1];
int allmask, n;
 
void init()
{
    memset(dp, -1, sizeof(dp));
    allmask = (1 << n) - 1;
}
 
int max(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}
 
int solve(int men, int mask)
{
    if (men == n){
        return 0;
    }
       
    if (dp[men][mask] != -1)
    {
        return dp[men][mask];
    }
       
    int sum = -1;
    for (int i = 0; i < n; i++){
        if (mask & (1 << i))
            continue;
        sum = max(sum, affinity[men][i] + solve(men + 1, mask | (1 << i)));
    }
    dp[men][mask] = sum;
    return dp[men][mask];
}
 
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; testCase++){
        cout << "Case " << testCase << ": ";
        cin >> n;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> affinity[i][j];
            }
        }
        init();
        cout << solve(0, 0) << endl;
    }
 
 
    return 0;
}