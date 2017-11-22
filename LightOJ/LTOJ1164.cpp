using namespace std;

#include <bits/stdc++.h>
#define si(x)       scanf("%d", &x)
#define sif(x)      scanf("%d", &x);getchar()
#define sl(x)       scanf("%lld", &x)
#define sf          scanf
#define pf          printf
#define pb          push_back
#define N           100005
#define M           1000000007

typedef long long int ll;

ll st[4*N];
ll lazy[4*N];

void update(int s, int e, int l, int r, int value, int sst)
{
    if(lazy[sst] != 0)
    {
        st[sst] += (e-s+1)*lazy[sst];

        if(s != e)
        {
            lazy[2*sst] += lazy[sst];
            lazy[2*sst+1] += lazy[sst];
        }
        lazy[sst] = 0;
    }

    if(s > r || e < l)
        return;

    if(s == e)
    {
        st[sst] += value;
        return;
    }
    if(s >= l && e <= r)
    {
        st[sst] += (e-s+1)*value;
        lazy[2*sst] += value;
        lazy[2*sst+1] += value;
        return;
    }
    int mid = (s+e)/2;
    update(s, mid, l, r, value, 2*sst);
    update(mid+1, e, l, r, value, 2*sst+1);
    st[sst] = st[2*sst]+st[2*sst+1];
}

ll query(int s, int e, int l, int r, int sst)
{
    if(lazy[sst] != 0)
    {
        st[sst] += (e-s+1)*lazy[sst];
        if(s!=e)
        {
            lazy[2*sst] += lazy[sst];
            lazy[2*sst+1] += lazy[sst];
        }
        lazy[sst] = 0;
    }

    if(s > r || e < l)
        return 0;

    if(s >= l && e <= r)
        return st[sst];

    int mid = (s+e)/2;
    return (query(s, mid, l, r, 2*sst)+query(mid+1, e, l, r, 2*sst+1));
}

int main()
{
    int n, q, i, t, mode, x, y, v, caseNo = 1;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    si(t);
    while(t--)
    {
        si(n);
        si(q);
        memset(st, 0, sizeof(st));
        memset(lazy, 0, sizeof(lazy));
        pf("Case %d:\n", caseNo++);
        for(i = 1; i <= q; i++)
        {
            si(mode);
            if(mode == 0)
            {
                si(x);
                si(y);
                si(v);
                update(0, n-1, x, y, v, 1);
            }
            else if(mode == 1)
            {
                si(x);
                si(y);
                pf("%lld\n", query(0, n-1, x, y, 1));
            }
        }
    }
    return 0;
}


