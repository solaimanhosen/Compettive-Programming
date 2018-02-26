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
    int t, a, b;
    map <int, int> mm;
    map <int, int> nn;
    si(t);
    while(t--)
    {
        si(a);
        si(b);
        mm[a] = b;
        nn[a]++;
        nn[b]--;
    }
    map <int, int>::iterator nni = nn.begin();
    while(nni -> second != 1) nni++;
    t = nni -> first;
    a = t;
    b = mm[0];
    t = 0;
    while(a && b)
    {
        if(t) pf(" ");
        pf("%d %d", a, b);
        a = mm[a];
        b = mm[b];
        t++;
    }
    if(a)
        pf(" %d", a);
    pf("\n");

    return 0;
}
