#include <bits/stdc++.h>
#define N 50000

using namespace std;

int main()
{
    int t, n, w, x, i, j, c, y[N+1], low;
    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        c = 1;
        scanf("%d %d", &n, &w);
        for(j = 1; j <= n; j++)
        {
            scanf("%d %d", &x, &y[j]);
        }
        sort(y+1, y+n+1);
        low = y[1] + w;
        for(j = 2; j <= n; j++)
        {
            if(y[j] > low)
            {
                c++;
                low = y[j] + w;
            }

        }
        printf("Case %d: %d\n", i, c);
    }

    return 0;
}
