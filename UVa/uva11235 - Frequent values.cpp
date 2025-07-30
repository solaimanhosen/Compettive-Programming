#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pfi(x) printf("%d\n", x)
#define pb push_back
#define N 165000

using namespace std;

typedef long long int ll;

int arr[N];
int st[6*N];
int counter[N];
int start[N];

void segmentTree(int s, int e, int sst)
{
    if(s == e){
        st[sst] = counter[s];
        return;
    }
    int mid = (s+e)/2;
    segmentTree(s, mid, 2*sst);
    segmentTree(mid+1, e, 2*sst+1);
    st[sst] = max(st[2*sst], st[2*sst+1]);
}

int query(int s, int e, int l, int r, int sst)
{
    if(l <= s && r >= e)
        return st[sst];
    if(l > e || r < s)
        return 0;
    int mid = (s+e)/2;
    return max(query(s, mid, l, r, 2*sst), query(mid+1, e, l, r, 2*sst+1));
}

int main()
{
    int n, q, i, j, a, b, cnt, temp, high, low, l, r;
    while(scanf("%d", &n) && n)
    {
        si(q);
        map <int, int> mm;
        cnt = 0;
        temp = INT_MIN;
        for(i = 1; i <= n; i++)
        {
            si(arr[i]);
            mm[arr[i]]++;
            if(temp != arr[i])
            {
                cnt = i;
                temp = arr[i];
            }
            start[i] = cnt;
        }
        for(i = 1; i <= n; i++)
            counter[i] = mm[arr[i]];
        segmentTree(1, n, 1);
        for(j = 0; j < q; j++)
        {
            si(a);
            si(b);
            cnt = 0;
            if(arr[a] == arr[b])
                cnt = (b-a)+1;
            else
            {
                low = a;
                high = start[a]+counter[a]-1;
                l = high+1;
                cnt = max(high-low+1, cnt);
                low = start[b];
                r = low-1;
                high = b;
                cnt = max(high-low+1, cnt);
                if(l < r)
                    cnt = max(cnt, query(1, n, l, r, 1));
            }
            pfi(cnt);
        }
    }

    return 0;
}

