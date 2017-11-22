using namespace std;
#include <bits/stdc++.h>

#define pf          printf
#define sf          scanf
#define si(x)       sf("%d",&x)
#define si2(x,y)    sf("%d %d",&x,&y)
#define si3(x,y,z)  sf("%d %d %d",&x,&y,&z)
#define ss(x)       sf("%s",x)
#define pfc(x)      pf("Case %d: ",x)
#define pfcn(x)     pf("Case %d:\n",x)
#define pfv(x)      pf("%d\n",x)
#define pb          push_back
#define ll          long long
#define f           first
#define s           second
#define N           10005

class Trie
{
	bool end;
	Trie *childs[10];

public:
	Trie(){
		end = false;
		for(int i = 0; i < 10; i++)
            childs[i] = NULL;
	}
	void del()
	{
		for(int i = 0; i < 10; i++)
			if(childs[i] != NULL)
			{
				childs[i]->del();
				delete childs[i];
			}
	}
	bool addWord(string &word, int pos)
	{
		if(end) return false;
		if(pos == word.length()) return end = true;
		const char c = word[pos] - '0';
		if(childs[c] == NULL)
			childs[c] = new Trie();
		return childs[c]->addWord(word, ++pos);
	}
} *root;

bool cmp(const string &str1, const string &str2)
{
	return (str1.length() == str2.length() ? str1 < str2 : str1.length() < str2.length());
}

string str[N];

int main()
{
	//freopen("input.txt", "r", stdin);

	int m, n, i, j, k, sum;
	int a, b, x, y;
	int tc, t;

	scanf("%d", &tc);

	for(t = 1; t <= tc; t++)
	{
		bool flag = true;
		root = new Trie();
		scanf("%d", &n);
		getchar();

		for(i = 0; i < n; i++)
			cin >> str[i];

		sort(str, str+n, cmp);
		for(i = 0; i < n && flag; i++)
			flag = root->addWord(str[i], 0);
		root->del();
		delete root;

		printf("Case %d: %s\n", t, (flag ? "YES" : "NO"));
	}

	return 0;
}

