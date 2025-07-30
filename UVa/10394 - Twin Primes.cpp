#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <list>
#include <map>

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
#define nl                  printf("\n")
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
#define MAXN                20000000
#define MAXM                100
#define MAX                 100001

bool mark[MAXN];
int tprime[MAXN];

void seive()
{
    for(int i = 3; i*i < MAXN; i+=2){
        if(!mark[i]){
            for(int j = i+i; j < MAXN; j+=i){
                mark[j] = 1;
            }
        }
    }
}

void twinPrime()
{
    int idx = 1;
    for(int i = 3; i < MAXN-2; i+=2){
        if(!mark[i] && !mark[i+2]){
            tprime[idx++] = i;
        }
    }
}

int main()
{
	//fli();
	//flo();

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    seive();
    twinPrime();
    int n;
    while(sf("%d", &n) == 1){
        printf("(%d, %d)\n", tprime[n], tprime[n]+2);
    }

	return 0;
}
