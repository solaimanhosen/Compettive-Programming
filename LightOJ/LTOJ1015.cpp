#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 31622800

using namespace std;

typedef long long int ll;

int main()
{
    int t, tc, n, dust, total;
    si(t);
    for(tc = 1; tc <= t; tc++)
    {
        si(n);
        total = 0;
        for(int j = 1; j <= n; j++)
        {
            si(dust);
            if(dust > 0)
                total += dust;
        }
        pf("Case %d: %d\n", tc, total);
    }

    return 0;
}


