using namespace std;

#include <bits/stdc++.h>
#define sf              scanf
#define si(x)           scanf("%d", &x)
#define sl(x)           scanf("%lld", &x)
#define pf              printf
#define pb              push_back
#define N               100005
#define PI              3.40954185
#define F               first
#define S               second

typedef long long int ll;

int arr[N+1];
int st[4*N];

void segmentTree(int s, int e, int sst)
{
    if(s == e)
    {
        st[sst] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    int left = 2*sst;
    int right = 2*sst+1;
    segmentTree(s, mid, left);
    segmentTree(mid+1, e, right);
    st[sst] = st[left]+st[right];
}

void update(int s, int e, int index, int sst)
{
    //pf("%d %d %d %d\n", s, e, index, sst);
    if(s > index || e < index)
        return;
    if(s == e)
    {
        st[sst] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    int left = 2*sst;
    int right = 2*sst+1;
    update(s, mid, index, left);
    update(mid+1, e, index, right);
    st[sst] = st[left]+st[right];
}

int query(int s, int e, int l , int r, int sst)
{
    //pf("%d %d %d %d\n", s, e, l, r, sst);
    if(s > r || e < l)
        return 0;
    if(s >= l && e <= r)
        return st[sst];
    int mid = (s+e)/2;
    int left = 2*sst;
    int right = 2*sst+1;
    return (query(s, mid, l, r, left)+query(mid+1, e, l, r, right));
}


int main()
{
    int t, n, q, i, j, a, b, mode, caseNo = 1;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    si(t);
    getchar();
    while(t--)
    {
        si(n);
        si(q);
        getchar();
        for(i = 0; i < n; i++)
            si(arr[i]);
        getchar();
        segmentTree(0, n-1, 1);
        pf("Case %d:\n", caseNo++);
        for(i = 1; i <= q; i++)
        {
            si(mode);
            if(mode == 1)
            {
                si(a);
                getchar();
                pf("%d\n", arr[a]);
                arr[a] = 0;
                update(0, n-1, a, 1);
            }
            if(mode == 2)
            {
                si(a);
                si(b);
                getchar();
                arr[a] += b;
                update(0, n-1, a, 1);
            }
            else if(mode == 3)
            {
                si(a);
                si(b);
                getchar();
                pf("%d\n", query(0, n-1, a, b, 1));
            }

        }

    }

    return 0;
}


