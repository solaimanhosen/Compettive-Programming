#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define N 10000

using namespace std;

int main()
{
    int n, sum[N+1];
    sum[0] = 0;
    for(int i = 1; i <= N; i++)
        sum[i] = sum[i-1] + i;
    while(si(n) == 1)
    {
        if(n <= 0)
            pff(1-sum[abs(n)]);
        else
            pff(sum[n]);
    }
    return 0;
}
