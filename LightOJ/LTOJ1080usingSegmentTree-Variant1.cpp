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

int tree[4*N], n;

void update(int idx, int st, int ed, int i, int j)
{
    if(st == i && ed == j)
    {
        tree[idx]++;
        return;
    }

    int l = idx*2;
    int r = l+1;
    int mid = (st+ed)/2;

    if(j <= mid)
        update(l, st, mid, i, j);
    else if(i > mid)
        update(r, mid+1, ed, i, j);
    else
    {
        update(l, st, mid, i, mid);
        update(r, mid+1, ed, mid+1, j);
    }
}

int query(int s, int e, int index, int idx)
{
    if(s > index || e < index)
        return 0;

    if(s == index && e == index)
        return tree[idx];

    int mid = (s+e)/2;
    int left = idx*2;
    int right = left+1;
    return (tree[idx]+ query(s, mid, index, left)+query(mid+1, e,index, right));
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
        sf("%s", str);
        n = strlen(str);

        for(i = 0; i < n; i++)
            if(str[i] == '1')
                update(1, 1, n, i+1, i+1);

        si(q);
        for(i = 1; i <= q; i++)
        {
            sf("%s", mode);
            if(mode[0] == 'I')
            {
                si(a);
                si(b);
                update(1, 1, n, a, b);
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
