#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("-Ofast")
//#define debug
#ifdef debug
#define d_pf            printf
#else
#define d_pf            //
#endif // debug

#define print(arr, n)       for(int i = 0; i < n; i++) printf("%d ", arr[i]); printf("\n")
#define fli()               freopen("in.txt", "r", stdin)
#define flo()               freopen("out.txt", "w", stdout)
#define sf          	    scanf
#define pf          	    printf
#define pf(n)               printf("%d", n)
#define pfc(i)              printf("Case %d:", i)
#define pfn(n)              printf("%d\n", n)
#define pb                  push_back
#define bl                  printf("\n")
#define spc                 putchar(' ')
#define ll                  long long
#define ull                 unsigned long long
#define ff                  first
#define ss                  second
#define pii         	    pair <int, int>
#define repe(i, st, ed)     for(int i=st; i<=ed; i++)
#define rep(i, st, ed)      for(int i=st; i<ed; i++)
#define repd(i, st, ed)     for(int i=st; i>=ed; i--)

template<typename T> int toInt(T t){ stringstream ss; ss << t; int r; ss >> r; return r; }

int nextInt(){
	string buffer;
	getline(cin, buffer);
	return toInt(buffer);
}

template<class t>inline bool fs(t &x)
{
	int c = getchar();
	int sgn = 1;
	while (~c&&c<'0' || c>'9')
	{
		if (c == '-')
			sgn = -1;
		c = getchar();
	}
	for (x = 0; ~c&&'0' <= c&&c <= '9'; c = getchar())
		x = x * 10 + c - '0';
	x *= sgn;
	return ~c;
}

#define MOD                 1000000007
#define MAXM                1000005
#define MAXN                100100
#define MAX                 100001

struct segment
{
    int one;
    int two;
    int three;
};

segment Tree[4*MAXN];
int lazy[4*MAXN];

void buildTree(int s, int e, int idx)
{
    if(s > e){
        return;
    }
    if(s == e){
        Tree[idx].one = 0;
        Tree[idx].two = 0;
        Tree[idx].three = 1;
        return;
    }
    int mid = (s+e)>>1;
    buildTree(s, mid, idx<<1);
    buildTree(mid+1, e, idx<<1|1);

    Tree[idx].three = Tree[2*idx].three + Tree[2*idx+1].three;
}

void propagate(int idx, int s, int e)
{
    lazy[idx] %= 3;
    for(int i = 0; i < lazy[idx]; i++){
        int temp = Tree[idx].three;
        Tree[idx].three = Tree[idx].two;
        Tree[idx].two = Tree[idx].one;
        Tree[idx].one = temp;
    }
    if(s < e){
        lazy[idx<<1] += lazy[idx];
        lazy[idx<<1 | 1] += lazy[idx];
    }
    lazy[idx] =0;
}

void update(int s, int e, int st, int ed, int idx)
{
    if(lazy[idx] != 0){
        propagate(idx, s, e);
    }
    if(s > ed || e < st || s > e){
        return;
    }
    if(s >= st && e <= ed){
        lazy[idx]++;
        propagate(idx, s, e);
        return;
    }
    int mid = (s+e)>>1;
    update(s, mid, st, ed, idx<<1);
    update(mid+1, e, st, ed, idx<<1|1);

    Tree[idx].one = Tree[idx<<1].one + Tree[idx<<1|1].one;
    Tree[idx].two = Tree[idx<<1].two + Tree[idx<<1|1].two;
    Tree[idx].three = Tree[idx<<1].three + Tree[idx<<1|1].three;
}

int query(int s, int e, int st, int ed, int idx)
{
    if(lazy[idx] != 0){
        propagate(idx, s, e);
    }
    if(s > ed || e < st || s > e){
        return 0;
    }
    if(s >= st && e <= ed){
        return Tree[idx].three;
    }
    int mid = (s+e)/2;
    return query(s, mid, st, ed, idx<<1) + query(mid+1, e, st, ed, idx<<1|1);
}

void init(int n)
{
    for(int i = 0; i < 4*MAXN; i++){
        Tree[i].one = Tree[i].two = Tree[i].three = 0;
        lazy[i] = 0;
    }
}

int main()
{
    //fli();
    //flo();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc, n, q, mode, x, y;
    fs(tc);
    rep(i, 1, tc+1){
        fs(n);fs(q);
        pfc(i);
        bl;
        init(n);
        buildTree(0, n-1, 1);
        repe(j, 1, q){
            fs(mode);fs(x);fs(y);
            if(!mode){
                update(0, n-1, x, y, 1);
            }
            if(mode){
                int ans = query(0, n-1, x, y, 1);
                pfn(ans);
            }
        }
    }

	return 0;
}
