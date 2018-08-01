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

#define MOD                 1000000007LL
#define MAXM                1000005
#define MAXN                100
#define MAX                 100001
#define BASE                257LL


ll getHash(string str, int n)
{
    ll hash = 0;
    for(int i = 0; i < n; i++){
        hash = ((hash*BASE)%MOD + str[i])%MOD;
    }
    return hash;
}

ll fastPow(ll base, ll pow)
{
    if(pow == 0){
        return 1;
    }
    if(pow == 1){
        return base;
    }
    ll x = fastPow(base, pow/2);
    x = (x*x)%MOD;
    if(pow % 2 == 1){
        x = (x*base)%MOD;
    }
    return x;
}

void solve(string pattern, string text)
{
    int counter = 0;
    int m = pattern.length();
    int n = text.length();
    ll hash_pattern = getHash(pattern, m);
    ll hash_text = getHash(text, m);
    if(hash_text == hash_pattern){
        cout << 0 << endl;
        counter++;
    }
    ll pow = fastPow(BASE, m-1);
    for(int i = m; i < n; i++){
        hash_text = (hash_text - (text[i-m]*pow)%MOD)%MOD;
        hash_text = (hash_text + MOD)%MOD;
        hash_text = (hash_text*BASE)%MOD;
        hash_text = (hash_text + text[i])%MOD;
        if(hash_text == hash_pattern){
            cout << (i-m+1) << endl;
            counter++;
        }
    }
    if(!counter){
        cout << endl;
    }
}

int main()
{
    //fli();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string pattern;
    string text;
    int n;
    while(getline(cin, pattern)){
        n = toInt(pattern);
        getline(cin, pattern);
        getline(cin, text);
        solve(pattern, text);
    }

	return 0;
}

