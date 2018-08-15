#include <bits/stdc++.h>
#define N 100

using namespace std;

int res[N+1][N+1];
int grid[N+1][N+1];

int main()
{
    int n, m, k, i, j, kx, ky;
    pair < int , int> p[N+2];

    cin >> n >> m >> k;
    for(i = 0; i < k; i++)
    {
        cin >> kx >> ky;
        grid[kx][ky] = 1;
        p[i] = make_pair(kx, ky);
    }
    int cnt = 1;
    i = j = 1;
    kx = ky = 1;
    while(true)
    {
        if((i == n && (j == 0 || j == m)) || (j == m && (i == 0 || i == n)))
        {
            puts("break1");
            cout << i << " "<< j << endl;
            break;
        }

        if(i == 0 && j == 0 && cnt > 1)
        {
            puts("break2");
            cout << i << " "<< j << endl;
            break;
        }

        if(grid[i][j] == 1)
            res[i][j] = cnt;


        if(i == n)
        {
            kx = -1;
        }
        if(j == m)
        {
            kx = -1;
            ky = -1;
        }
        if(i == 1 && j != 1)
        {
            kx = 1;
            ky = -1;
        }
        if(j == 1 && i != 1)
        {
            kx = 1;
            ky = 1;
        }
        cnt++;
        i += kx;
        j += ky;
        puts("working");

    }
    for(i = 0; i < k; i++)
    {
        if(res[p[i].first][p[i].second] > 0)
            cout << res[p[i].first][p[i].second] << endl;
        else
            cout << "-1"<< endl;
    }

    return 0;

}
