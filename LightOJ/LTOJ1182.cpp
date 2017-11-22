#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, caseNo = 1, n, cnt;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        cnt = 0;
        while(n!=0)
        {
            if(n%2==1) cnt++;
            n/=2;
        }
        printf("Case %d: %s", caseNo++, cnt&1 ? "odd\n":"even\n");
    }
    return 0;
}

