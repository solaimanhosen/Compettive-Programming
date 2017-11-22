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

int tree[4*N], lazy[4*N], n;

void makeTree(int s, int e, int index, int idx)
{
    if(s > index || e < index)
        return;
    if(s == index && e == index)
    {
        tree[idx]++;
        return;
    }
    int mid = (s+e)/2;
    int left = 2*idx;
    int right = left+1;

    makeTree(s, mid, index, left);
    makeTree(mid+1, e, index, right);
}

void update(int s, int e, int l, int r, int idx)
{
    if(lazy[idx] != 0)
    {
        if(s == e)
        {
            tree[idx]+= lazy[idx];
            lazy[idx] = 0;
        }
        if(s != e)
        {
            lazy[2*idx] += lazy[idx];
            lazy[2*idx+1] += lazy[idx];
            lazy[idx] = 0;
        }
    }
    if(s > r || e < l)
        return;
    if(s >= l && e <= r)
    {
        lazy[idx]++;
        return;
    }
    int left = 2*idx;
    int right = left+1;
    int mid = (s+e)/2;

    update(s, mid, l, r, left);
    update(mid+1, e, l, r, right);
}

int query(int s, int e, int index, int idx)
{
    if(lazy[idx] != 0)
    {
        if(s == e)
        {
            tree[idx]+= lazy[idx];
            lazy[idx] = 0;
        }
        if(s != e)
        {
            lazy[2*idx] += lazy[idx];
            lazy[2*idx+1] += lazy[idx];
            lazy[idx] = 0;
        }
    }
    if(s > index || e < index)
        return 0;

    if(s == index && e == index)
        return tree[idx];

    int left = 2*idx;
    int right = left +1;
    int mid = (s+e)/2;

    return (query(s, mid, index, left)+query(mid+1, e, index, right));
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char str[N];
    int i, j, caseNo = 1, q, a, b;
    int t;
    char mode[3];
    si(t);
    while(t--)
    {
        pf("Case %d:\n", caseNo++);
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        sf("%s", str);
        n = strlen(str);

        for(i = 0; i < n; i++)
            if(str[i] == '1')
                makeTree(1, n, i+1, 1);

        si(q);
        for(i = 1; i <= q; i++)
        {
            sf("%s", mode);
            if(mode[0] == 'I')
            {
                si(a);
                si(b);
                update(1, n, a, b, 1);
            }
            else
            {
                si(a);
                pf("%d\n", query(1, n, a, 1)%2);
            }
        }
    }
    return 0;
}

