#include <bits/stdc++.h>
#define N 100

using namespace std;

int main()
{
    int t, caseno, n, num[N+1], i, j, moveNum;
    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        for(j = 1; j <= n; j++)
            scanf("%d", &num[j]);
        moveNum = 0;
        for(j = 1; j <= n; j++)
        {
            while(num[j] != j)
            {
                swap(num[j], num[num[j]]);
                moveNum++;
            }
        }
        printf("Case %d: %d\n", i, moveNum);
    }

    return 0;
}
