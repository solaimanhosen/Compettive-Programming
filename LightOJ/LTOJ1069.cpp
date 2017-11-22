
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
    int t, i, x, y;
    si(t);
    for(i = 1; i <= t; i++)
    {
        sf("%d %d", &x, &y);
        pf("Case %d: %d\n", i, (abs(x-y)+x)*4+19);
    }
    return 0;
}
