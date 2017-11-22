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
    int t, n, m , i , j, k, num, arr[105];
    char ch;
    si(t);
    for(i = 1; i <= t; i++)
    {
        scanf(" %d %d", &n, &m);
        for(j = 0; j < n; j++)
            sf(" %d", &arr[j]);
        for(j = 1; j <= m; j++)
        {
            scanf(" %c", &ch);
            if(ch == 'S')
            {
                scanf(" %d", &num);
                for(k = 0; k < n; k++)
                    arr[k] += num;
            }
            else if(ch == 'M')
            {
                scanf(" %d", &num);
                for(k = 0; k < n; k++)
                    arr[k] *= num;
            }
            else if(ch == 'D')
            {
                scanf(" %d", &num);
                for(k = 0; k < n; k++)
                    arr[k] /= num;
            }
            else if(ch == 'R')
            {
                reverse(arr, arr+n);
            }
            else if(ch == 'P')
            {
                int x, y;
                scanf("%d %d", &x, &y);
                swap(arr[x], arr[y]);
            }
        }
        pf("Case %d:\n", i);
        for(j = 0; j < n; j++)
            pf("%d%c", arr[j], j == n-1?'\n':' ');
    }

    return 0;
}

