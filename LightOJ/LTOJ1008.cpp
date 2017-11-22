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
    int t, tc;
    ll s, root, row, col;
    si(t);
    for(tc = 1; tc <= t; tc++)
    {
        sf("%lld", &s);
        root = ceil(sqrt(double(s)));
        if(root*root - s < root)
            row = root, col = root*root -s + 1;
        else
            col = root, row = s- (root-1)*(root-1);
        if(!(root&1))
            swap(row, col);
        pf("Case %d: %lld %lld\n", tc, col, row);
    }

    return 0;
}

