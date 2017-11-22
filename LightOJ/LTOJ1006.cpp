#include <bits/stdc++.h>
#define N 10000
#define MOD 10000007

using namespace std;

int main()
{
    int tc, cn, n;
    long long dp[N+1];
    cin >> tc;
    cn = 1;
    while(tc--)
    {
       cin >> dp[0] >> dp[1] >> dp[2] >> dp[3] >> dp[4] >> dp[5] >> n;
       for(int i = 6; i <= n; i++)
       {
           dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6];
           if(dp[i] >= MOD)
           {
               dp[i] = dp[i]%MOD;
           }
       }
       cout << "Case " << cn++ << ": " << dp[n]%MOD << endl;
    }

    return 0;
}
