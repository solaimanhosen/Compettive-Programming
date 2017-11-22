using namespace std;

#include <bits/stdc++.h>
#define sf              scanf
#define si(x)           scanf("%d", &x)
#define ss(x)           scanf("%s", x)
#define sl(x)           scanf("%lld", &x)
#define pf              printf
#define pb              push_back
#define N               100005
#define PI              3.40954185
#define F               first
#define S               second

typedef long long int ll;

int arr[N], n, tree[N];

void update(int idx, int value)
{
    while(idx <= n)
    {
        tree[idx]+= value;
        idx += idx & (-idx);
    }
}

int query(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, i, j, q, caseNo = 1, x, y;
    char str[N], mode[3];

    si(t);
    while(t--)
    {
        memset(tree, 0, sizeof(tree));
        ss(str);
        n = strlen(str);

        for(i = 0; i < n; i++)
            arr[i+1] = str[i]-'0';

        si(q);
        pf("Case %d:\n", caseNo++);
        for(i = 1; i <= q; i++)
        {
            ss(mode);

            switch(mode[0])
            {
            case 'I':
                si(x);
                si(y);
                update(x, 1);
                update(y+1, -1);
                break;
            case 'Q':
                si(x);
                pf("%d\n", arr[x] ^ query(x)%2);
            }
        }
    }

    return 0;
}
