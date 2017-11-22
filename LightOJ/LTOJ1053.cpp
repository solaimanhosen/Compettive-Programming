
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
    int t, num[3];
    si(t);
    for(int i = 1; i <= t; i++)
    {
        sf("%d %d %d", &num[0], &num[1], &num[2]);
        sort(num+0, num+3);
        if(num[0]*num[0]+num[1]*num[1] == num[2]*num[2])
            pf("Case %d: yes\n", i);
        else
            pf("Case %d: no\n", i);
    }

    return 0;
}
