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
#define ll                  long long int
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

#define MOD                 1000003
#define MAXM                1000005
#define MAXN                100000
#define MAX                 100000

struct Table{
    string key;
    string value;
    int index;
    Table()
    {
        index = -1;
    }
};

Table hashTable[MOD];
const ll BASE = 257;
int idx;

inline ll findHash(string str, ll BASE, ll M)
{
    ll hash = 0;
    ll pow = 1;
    int len = str.length();
    for(int i = len - 1; i >= 0; i--){
        hash = (hash + (str[i]*pow)%M)%M;
        pow = (pow*BASE)%M;
    }
    return hash;
}

void parseText(string line, string& key, string& value)
{
    stringstream ss(line);
    ss >> value;
    ss >> key;
}

void insert(string key, string value)
{
    ll hash = findHash(key, BASE, MOD);
    while(hashTable[hash].index != -1){
        hash = (hash+1)%MOD;
    }
    hashTable[hash].index = 1;
    hashTable[hash].key = key;
    hashTable[hash].value = value;
}

void search(string key)
{
    bool found = false;
    ll hash = findHash(key, BASE, MOD);
    while(hashTable[hash].index != -1) {
        if(hashTable[hash].key.compare(key) == 0){
            cout << hashTable[hash].value << endl;
            found = true;
            break;
        }
        hash = (hash+1)%MOD;
    }
    if(!found) cout << "eh" << endl;
}

int main()
{
    //fli();
    //flo();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line, key, value;
    while(true){
        getline(cin, line);
        if(line.length() == 0) break;
        parseText(line, key, value);
        insert(key, value);
    }
    while(getline(cin, key)){
        search(key);
    }


    return 0;
}