#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 165000

using namespace std;

typedef long long int ll;

int main()
{
    int t, i, x1, x2, y1, y2, x, y, m;
    si(t);
    for(i = 1; i <= t; i++)
    {
        sf("%d %d %d %d", &x1, &y1, &x2, &y2);
        si(m);
        pf("Case %d:\n", i);
        for(int j = 1; j <= m; j++)
        {
            sf("%d %d", &x, &y);
            if((x > min(x1, x2) && x < max(x1, x2)) && (y > min(y1, y2) && y < max(y1, y2)))
                pf("Yes\n");
            else
                pf("No\n");
        }
    }
    return 0;
}
