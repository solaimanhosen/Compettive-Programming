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
#define MAXN                250
#define MAXM                100
#define MAX                 100001

int arr1[MAXN*MAXN+5];
int arr2[MAXN*MAXN + 5];
int seq[MAXN*MAXN + 5];
int lis[MAXN*MAXN + 5];
int idx;

int findLIS(){
	int len = 1;
	lis[0] = seq[0];
	for (int i = 1; i < idx; i++){
		int j = len-1;
		if (seq[i] < lis[0]){
			lis[0] = seq[i];
		}
		else if (seq[i] > lis[j]){
			lis[len++] = seq[i];
		}
		else{
			while (j >= 0 && lis[j] > seq[i]){
				j--;
			}
			lis[j+1] = seq[i];
		}
	}
	return len;
}

int main()
{
	//fli();
	//flo();

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc, n, p, q;
	fs(tc);
	for (int cc = 1; cc <= tc; cc++){
		fs(n);
		fs(p);
		fs(q);
		repe(i, 0, p){
			fs(arr1[i]);
		}
		repe(i, 0, q){
			fs(arr2[i]);
		}
		idx = 0;
		repe(i, 0, p){
			repe(j, 0, q){
				if (arr1[i] == arr2[j]){
					seq[idx++] = j;
					break;
				}
			}
		}
		pfc(cc);
		spc;
		pfn(findLIS());
	}


	return 0;
}
