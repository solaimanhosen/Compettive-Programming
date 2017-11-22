#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 1000000000000000000

using namespace std;

typedef long long int ll;

int main()
{
    int t = 1, caseNo = 1;
    ll n;
    vector <ll> fact;
    fact.pb(1);
    n = fact.back();
    while(n < N)
    {
        fact.pb(t*n);
        n = fact.back();
        t++;
    }
    si(t);
    while(t--)
    {
        sf("%lld", &n);
        vector<int> ans;
        for(int k = 20; k >= 0; k--)
        {
            if(!n)
                break;
            if(fact[k] <= n)
            {
                ans.pb(k);
                n -= fact[k];
            }
        }
        reverse(ans.begin(), ans.end());
        if(!n)
        {
            pf("Case %d: ", caseNo++);
            for(int k = 0; k < ans.size()-1; k++)
                pf("%d!+", ans[k]);
            pf("%d!\n", ans[ans.size()-1]);
        }
        else
            pf("Case %d: impossible\n", caseNo++);
    }

    return 0;
}

