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
    int t, b, caseNo = 1;
    char num[205];
    si(t);
    while(t--)
    {
        sf(" %s %d", num, &b);
        b = abs(b);
        int len = strlen(num);
        ll sum = 0;
        int i = 0;
        if(num[0] == '-')
            i = 1;
        for(i; i < len; i++)
        {
            sum += (num[i] - '0');
            if(sum >= b)
                sum = sum%b;
            if(i != len-1)
                sum = sum*10;
        }
        if(sum) pf("Case %d: not divisible\n", caseNo++);
        else pf("Case %d: divisible\n", caseNo++);
    }
    return 0;
}

