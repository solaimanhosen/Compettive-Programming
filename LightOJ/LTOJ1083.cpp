#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 30005

using namespace std;

typedef long long int ll;

int maxi(int a, int b, int c)
{
    int d = max(a, b);
    return max(c,d);
}

int minIndex(int hist[], int i, int j)
{
    if(i == -1) return j;
    if(j == -1) return i;
    if(hist[i] < hist[j])
        return i;
    return j;
}

int segmentTree(int hist[], int s, int e, int *st, int sst)
{
    if(s == e)
    {
        st[sst] = s;
        return st[sst];
    }

    else
    {
        int mid = (s+e)/2;
        st[sst] =  minIndex(hist,segmentTree(hist, s, mid, st, 2*sst+1), segmentTree(hist, mid+1, e, st, 2*sst+2));
        return st[sst];
    }

}

int RMQ(int hist[], int st[], int s, int e, int l, int r, int sst)
{
    if(l <= s && r >= e)
        return st[sst];
    if(l > e || r < s)
        return -1;
    int m = (s+e)/2;
    return minIndex(hist, RMQ(hist, st, s, m, l, r, 2*sst+1), RMQ(hist, st, m+1, e, l, r, 2*sst+2));
}
int getMaxAreaRec(int *hist, int *st, int n, int l, int r)
{
    if (l > r)  return -1;
    if (l == r)  return hist[l];

    int m = RMQ(hist, st, 0, n-1, l, r, 0);

    int mm = maxi(getMaxAreaRec(hist, st, n, l, m-1),
               getMaxAreaRec(hist, st, n, m+1, r),
               ((r-l)+1)*(hist[m]));
    return mm;
}

int main()
{
    int hist[N], t, i, n, caseNo = 1;
    si(t);
    while(t--)
    {
        si(n);
        int x = (int)ceil(log2(n));
        int max_size = 2*(int)pow(2, x) - 1;
        int *st = new int[max_size];
        for(i = 0; i < n; i++)
            si(hist[i]);
        segmentTree(hist, 0, n-1, st, 0);

        int area = getMaxAreaRec(hist, st, n, 0, n-1);
        pf("Case %d: %d\n",caseNo++, area);
    }
    return 0;
}


