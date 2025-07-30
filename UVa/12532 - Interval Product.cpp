#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pfi(x) printf("%d\n", x)
#define pb push_back
#define N 100007

using namespace std;

typedef long long int ll;

int arr[N];
int st[6000007];

void segmentTree(int s, int e, int sst)
{
    if(s == e)
    {
        st[sst] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    segmentTree(s, mid, 2*sst);
    segmentTree(mid+1, e, 2*sst+1);
    st[sst] = st[2*sst]*st[2*sst+1];
}

int query(int s, int e, int l,int r, int sst)
{
    if(l <= s && r >= e)
        return st[sst];
    if(l > e || r < s)
        return 1;
    int mid = (s+e)/2;
    return (query(s, mid, l, r, 2*sst)*query(mid+1, e, l, r, 2*sst+1));
}

void update(int s, int e, int a, int b, int sst)
{
    if(s > a || e < a)
        return;
    if(s == e)
    {
        st[sst] = b;
        return;
    }

    if(s != e)
    {
        int mid = (s+e)/2;
        update(s, mid, a, b, 2*sst);
        update(mid+1, e, a, b, 2*sst+1);
        st[sst] = st[2*sst]*st[2*sst+1];
        return;
    }
}

int main()
{
    int n, k, t, i, j, a, b;
    char ch;
    while(scanf("%d %d", &n, &k) == 2)
    {
        for(i = 0; i < n; i++)
        {
            si(a);
            if(a > 0) a = 1;
            if(a < 0) a = -1;
            arr[i] = a;
        }
        segmentTree(0, n-1, 1);
        for(j = 0; j < k; j++)
        {
            cin >> ch;
            if(ch == 'P')
            {
                si(a);
                si(b);
                a--;
                b--;
                int q = query(0, n-1, a, b, 1);
                if(q > 0) pf("+");
                if(q < 0) pf("-");
                if(q == 0) pf("0");
            }
            else
            {
                si(a);
                si(b);
                a--;
                if(b > 0) b = 1;
                if(b < 0) b = -1;
                update(0, n-1, a, b, 1);
                arr[a] = b;
            }
        }
        pf("\n");
    }

    return 0;
}



