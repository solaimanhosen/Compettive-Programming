#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 165000

using namespace std;

typedef long long int ll;

int solve(int n)
{
    if(!n)
        return 0;
    int res = (n/3)*2;
    if(n%3 == 2)
        res++;
    return res;
}

int main()
{
    int t, i, j, a, b;
    si(t);
    for(i = 1; i <= t; i++)
    {
        sf("%d %d", &a, &b);
        pf("Case %d: %d\n", i, solve(b)-solve(a-1));
    }


    return 0;
}

