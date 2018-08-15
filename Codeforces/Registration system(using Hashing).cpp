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

#define MOD1                1159517
#define MOD2                1000000037
#define MAXM                1000005
#define MAXN                1159517
#define MAX                 100001
#define BASE1               437
#define BASE2               257

struct Node
{
    //string word;
    ll hash;
    int counter;
    Node(){
        counter = 0;
    }
};

Node pool[MAXN];
ll hashTable[MAXN];
int idx;

void findHash(string word)
{
    ll pow1 = 1;
    ll pow2 = 1;
    ll hash1 = 0;
    ll hash2 = 0;
    for(int i = 0; i < word.length(); i++){
        hash1 = (hash1 + (word[i]*pow1)%MOD1)%MOD1;
        hash2 = (hash2 + (word[i]*pow2)%MOD2)%MOD2;
        pow1 = (pow1*BASE1)%MOD1;
        pow2 = (pow2*BASE2)%MOD2;
    }
    //cout << word << ": " << hash1 << " " << hash2 << endl;
    if(hashTable[hash1] == 0){
        pool[idx].hash = hash2;
        pool[idx].counter++;
        //pool[idx].word = word;
        hashTable[hash1] = idx;
        cout << "OK" << endl;
        idx++;
    }
    else{
        bool res = false;
        while(hashTable[hash1] != 0){
            if(pool[hashTable[hash1]].hash == hash2){
                cout << word << pool[hashTable[hash1]].counter++ << endl;
                res = true;
                break;
            }
            hash1 = (hash1+1)%MOD1;
        }
        if(!res){
            pool[idx].hash = hash2;
            pool[idx].counter++;
            //pool[idx].word = word;
            hashTable[hash1] = idx;
            cout << "OK" << endl;
            idx++;
        }
    }
}

int main()
{
    fli();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string word;
    idx = 1;
    n = nextInt();
    for(int i = 1; i<= n; i++){
        getline(cin, word);
        findHash(word);
    }

	return 0;
}

