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

ll solve(ll n, int digit[])
{
    int i, cnt = 0;
    ll num = 0, posval = 1;
    while(n != 0)
    {
        digit[i++] = n % 2;
        n/=2;
    }
    for(i = 0; i <=32; i++)
    {
        if(digit[i] == 1)
        {
            cnt++;
            if(digit[i+1] == 0)
            {
                swap(digit[i], digit[i+1]);
                break;
            }
        }
    }
    for(int j = 0; j <i; j++)
    {
        if(j <cnt-1)
            digit[j] = 1;
        else
            digit[j] = 0;
    }
    for(i = 0; i <=32; i++)
    {
        num += digit[i]*posval;
        posval *= 2;
    }
    return num;
}

int main()
{
    int t, CaseNo, cnt, digit[33];
    ll n;
    si(t);
    for(CaseNo = 1; CaseNo <= t; CaseNo++)
    {
        sf("%lld", &n);
        memset(digit, 0, sizeof digit);
        pf("Case %d: %lld\n", CaseNo, solve(n, digit));
    }


    return 0;
}


