
#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 31622800
#define PI 2*acos(0.0)

using namespace std;

typedef long long int ll;

int main()
{
    int t, CaseNo;
    double r;
    si(t);
    for(CaseNo = 1; CaseNo <= t; CaseNo++)
    {
        sf("%lf", &r);
        pf("Case %d: %.2lf\n", CaseNo, 4*r*r - PI*r*r);
    }


    return 0;
}


