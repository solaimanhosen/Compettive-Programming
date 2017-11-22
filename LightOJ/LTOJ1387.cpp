#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf(" %d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 165000

using namespace std;

typedef long long int ll;

int main()
{
    char comm[10];
    int amount, num, t, caseNo = 1, n;
    si(t);
    while(t--)
    {
        si(n);
        pf("Case %d:\n",caseNo++);
        amount = 0;
        for(int i = 0; i < n; i++)
        {
            sf(" %s", comm);
            if(!strcmp(comm,"donate"))
            {
                si(num);
                amount += num;
            }
            else
                pff(amount);
        }
    }
    return 0;
}

