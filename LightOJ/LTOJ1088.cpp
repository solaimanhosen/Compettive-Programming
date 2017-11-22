#include <bits/stdc++.h>
#define sf(x)           scanf("%d", &x)
#define N               100000

using namespace std;

int main()
{
    int arr[N+5], i, j, n, q, t, caseNo = 1, l, r, ans;
    sf(t);
    while(t--)
    {
        sf(n);
        sf(q);
        for(i = 0; i < n; i++)
            sf(arr[i]);
        //sort(arr, arr+n);
        printf("Case %d:\n", caseNo++);
        for(i = 1; i <= q; i++)
        {
            sf(l);
            sf(r);
            ans = upper_bound(arr,arr+n, r)- arr;
            if(l > 0)
                ans -= upper_bound(arr, arr+n, l-1)-arr;
            printf("%d\n", ans);
        }
    }

    return 0;
}
