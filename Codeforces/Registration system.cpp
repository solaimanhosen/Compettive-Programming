using namespace std;

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

template<typename T> int toInt(T t){ stringstream ss; ss << t; int r; ss >> r; return r; }
string buffer;
int nextInt(){
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

struct Node
{
	int counter;
	struct Node* next[26];
	Node(){
		counter = 0;
		for (int i = 0; i < 26; i++){
			next[i] = 0;
		}
	}
};

struct Trie
{
	Node* head;
	Trie()
	{
		head = new Node;
	}
	int query(string str)
	{
		int index;
		Node* curr = head;
		for (int i = 0; i < str.length(); i++){
			index = (int)(str[i] - 'a');
			if (!curr->next[index]){
				curr->next[index] = new Node;
			}
			curr = curr->next[index];
		}
		return curr->counter++;
	}
};

int main()
{
	//freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc, res;
	string str;
	//fs(tc);
	tc = nextInt();
	Trie tree;
	while (tc--){
		getline(cin, str);
		res = tree.query(str);
		if (res == 0){
			cout << "OK" << endl;
		}
		else {
			cout << str << res << endl;
		}
	}

	return 0;
}