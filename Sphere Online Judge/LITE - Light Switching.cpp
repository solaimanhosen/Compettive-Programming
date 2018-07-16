#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("-Ofast")
//#define debug
#ifdef debug
#define d_pf            printf
#else
#define d_pf            //
#endif // debug

#define print(arr, n)   for(int i = 0; i < n; i++) printf("%d ", arr[i]); printf("\n");
#define MAX     1000000
#define C       53
#define fli()   freopen("in.txt", "r", stdin);
#define flo()   freopen("out.txt", "w", stdout);

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

int tree[4*MAX];
int lazy[4*MAX];

void update(int s, int e, int st, int ed, int idx)
{
    if(lazy[idx] != 0){
        if(lazy[idx] % 2 == 1){
            tree[idx] = (e-s+1)-tree[idx];
        }
        if(s!=e){
            lazy[2*idx] += lazy[idx];
            lazy[2*idx+1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if(s > ed || e < st || s > e){
        return;
    }
    if(s >= st && e <= ed && s <= e){
        tree[idx] = (e-s+1)-tree[idx];
        if(s!=e){
            lazy[2*idx]++;
            lazy[2*idx+1]++;
        }
        return;
    }
    int mid = (s+e)/2;
    update(s, mid, st, ed, 2*idx);
    update(mid+1, e, st, ed, 2*idx+1);
    tree[idx] = tree[2*idx] + tree[2*idx+1];
}

int query(int s, int e, int st, int ed, int idx)
{
    if(lazy[idx] != 0){
        if(lazy[idx] % 2 == 1){
            tree[idx] = (e-s+1)-tree[idx];
        }
        if(s!=e){
            lazy[2*idx] += lazy[idx];
            lazy[2*idx+1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if(s > ed || e < st || s > e){
        return 0;
    }
    if(s >= st && e <= ed && s <= e){
        return tree[idx];
    }
    int mid = (s+e)/2;
    return query(s, mid, st, ed, 2*idx) + query(mid+1, e, st, ed, 2*idx+1);
}

int main()
{
    //fli();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, mode, st, ed;
    fs(n);
    fs(q);
    while(q--){
        fs(mode);
        fs(st);
        fs(ed);
        d_pf("%d %d %d\n", mode, st, ed);
        if(mode == 0){
            update(1, n, st, ed, 1);
        }else{
            int ans = query(1, n, st, ed, 1);
            printf("%d\n", ans);
        }
        #ifdef debug
        print(tree, 8);
        print(lazy, 8)
        #endif // debug

    }

	return 0;
}
