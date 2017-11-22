#include <bits/stdc++.h>
#define N 100

using namespace std;

int main()
{
    int dp[2*N+5][2*N+5], tc, cn, i, j, k, n, nx, ny, m, temp;
    bool sign;
    cin >> tc;
    cn = 1;
    while(tc--)
    {
        sign = true;
        memset(dp, 0, sizeof(dp));
        cin >> n;
        j = 1;
        for(i = 1; i <= 2*n-1; i++)
        {
            for(k = 1; k <= j; k++)
            {
                cin >> temp;
                if(sign)
                {
                    nx = i - 1;
                    ny = k - 1;
                    if(nx >= 1 && ny <= j-1)
                    {
                        dp[i][k] = max(dp[i][k], temp + dp[nx][ny]);
                    }
                    nx = i - 1;
                    ny = k;
                    if(nx >= 1 && ny <= j-1)
                    {
                        dp[i][k] = max(dp[i][k], temp + dp[nx][ny]);
                    }
                }
                else
                {
                    nx = i - 1;
                    ny = k + 1;
                    if(nx >= 1 && ny <= j+1)
                    {
                        dp[i][k] = max(dp[i][k], temp + dp[nx][ny]);
                    }
                    nx = i - 1;
                    ny = k;
                    if(nx >= 1 && ny <= j+1)
                    {
                        dp[i][k] = max(dp[i][k], temp + dp[nx][ny]);
                    }
                }
                if(dp[i][k] < temp)
                    dp[i][k] = temp;
            }
            if(j < n && sign)
                j++;
            else
            {
                j--;
                sign = false;
            }
        }
        cout << "Case " << cn++ << ": " << dp[i-1][j+1] << endl;
    }

    return 0;
}
