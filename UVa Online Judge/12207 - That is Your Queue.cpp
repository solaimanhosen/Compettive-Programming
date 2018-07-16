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
#define MAXN                1000005
#define MAXN                100
#define MAX                 100001

int main()
{
	//fli();
	//flo();

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int p, q, x, idx, caseNo = 1;
	char mode;
	while (true){
		sf("%d %d", &p, &q);
		d_pf("%d %d\n", p, q);
		if (p == 0 && q == 0){
			break;
		}
		pfc(caseNo++);
		nl;
		if (p <= 1000) {
			list<int>List;
			list<int>::iterator it;
			for (int i = 1; i <= p; i++){
				List.pb(i);
			}
			while (q--){
				sf(" %c", &mode);
				d_pf("%c ", mode);
				if (mode == 'N') {
					x = List.front();
					List.pop_front();
					List.push_back(x);
					pfn(x);
				}
				else {
					fs(x);
					d_pf("%d", x);
					for (it = List.begin(); it != List.end(); it++){
						if (*(it) == x){
							break;
						}
					}
					//it = List.find(x);
					List.erase(it);
					List.push_front(x);
				}
				d_pf("\n");
			}
		}
		else {
			idx = 1;
			list<int>List;
			list<int>::iterator it;
			map<int, int>mark;
			while (q--){
				sf(" %c", &mode);
				d_pf("%c ", mode);
				if (mode == 'N') {
					if (!List.empty()) {
						x = List.front();
						List.pop_front();
						pfn(x);
					}
					else {
						while (mark[idx]){
							idx++;
						}
						pfn(idx++);
					}
				}
				else {
					fs(x);
					d_pf("%d", x);
					if (!List.empty()){
						for (it = List.begin(); it != List.end(); it++){
							if (*it == x){
								List.erase(it);
								break;
							}
						}
						List.push_front(x);
						mark[x] = true;
					}
					else{
						List.push_front(x);
						mark[x] = 1;
					}
				}
				d_pf("\n");
			}
		}
	}

	return 0;
}
