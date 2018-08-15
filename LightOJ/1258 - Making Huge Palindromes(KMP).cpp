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
#define MAXN                100
#define MAX                 100001

int lps[MAXM];

void computeLps(string pattern)
{
    int m = pattern.length();
    int i = 1;
    int j = 0;
    lps[j] = 0;
    while (i < m){
        if (pattern[i] == pattern[j]){
            lps[i] = j + 1;
            i++;
            j++;
        }
        else{
            if (j != 0){
                j = lps[j - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int findMatching(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    int i = 0;
    int j = 0;
    while (i < n){
        if (text[i] == pattern[j]){
            i++;
            j++;
        }
        else if(i < n && text[i] != pattern[j]){
            if (j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    return j;
}

void reverse(const string text, string& pattern)
{
    pattern = "";
    for(int i = text.length()-1; i >= 0; i--){
        pattern += text[i];
    }
}

int main()
{
    //fli();
    //flo();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string pattern;
    string text;
    int tc, caseNo = 1;
    tc = nextInt();
    while(tc--){
        getline(cin, text);
        reverse(text, pattern);
        computeLps(pattern);
        int match = findMatching(text, pattern);
        int len = text.length();
        cout << "Case " << caseNo++ << ": " << len+(len-match) << endl;
    }

	return 0;
}

