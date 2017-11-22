
#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 100007

using namespace std;

typedef long long int ll;

int arr[N];
int st[262145];

int segmentTree(int s, int e, int sst)
{
    if(s == e)
        st[sst] = arr[s];
    else
    {
        int mid = (s+e)/2;
        st[sst] = min(segmentTree(s, mid, 2*sst+1), segmentTree(mid+1, e, 2*sst+2));
    }
    return st[sst];
}

int RMQ(int s, int e, int l, int r, int sst)
{
    if(l <= s && r >= e)
        return st[sst];
    if(l > e || r < s)
        return INT_MAX;
    int mid = (s+e)/2;
    return min(RMQ(s, mid, l, r, 2*sst+1), RMQ(mid+1, e, l, r, 2*sst+2));
}

int main()
{
    int n, q, i, j, t, caseNo = 1, l, r;
    si(t);
    while(t--)
    {
        si(n);
        si(q);
        for(i = 1; i <= n; i++)
            si(arr[i]);
        segmentTree(1, n, 0);

        pf("Case %d:\n", caseNo++);
        for(j = 0; j < q; j++)
        {
            si(l);
            si(r);
            pff(RMQ(1, n, l, r, 0));
        }
    }

    return 0;
}
