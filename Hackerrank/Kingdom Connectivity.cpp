#include <iostream>
#include <stdio.h>

using namespace std;

#define N	10007
#define MOD	1000000000

template<class T> class Vector
{
	T myVector[N];
	int index;
public:
	Vector()
	{
		index = -1;
	}
	void push_back(T x)
	{
		if (index == -1){
			index = 0;
			myVector[index] = x;
			return;
		}
		index = (index + 1) % N;
		myVector[index] = x;
	}
	int size()
	{
		return (index + 1);
	}
	T valueAt(int i)
	{
		return myVector[i];
	}
	void clear()
	{
		index = -1;
	}
};

Vector<int>g[N];
bool visit[N];
bool Stack[N];
long long ways[N];
int n, m;



bool isCycle(int src)
{
	if (!visit[src]){
		visit[src] = true;
		Stack[src] = true;
		for (int i = 0; i < g[src].size(); i++){
			int v = g[src].valueAt(i);
			//int v = g[src][i];
			if (!visit[v]){
				return isCycle(v);
			}
			else if (Stack[v])
				return true;
		}
		Stack[src] = false;
	}
	
	return false;
}

long long findWays(int src)
{
	if (!visit[src]){
		
		if (src == n){
			visit[src] = true;
			ways[src] = 1;
			return ways[src];
		}
		visit[src] = true;
		int way = 0;
		for (int i = 0; i < g[src].size(); i++){
			int v = g[src].valueAt(i);
			//int v = g[src][i];
			if (!visit[v]){
				way = (findWays(v) + way) % MOD;
			}
			else{
				way = (ways[v] + way) % MOD;
			}

		}
		ways[src] = way;
		
	}
	return ways[src];
}

void init()
{
	for (int i = 0; i <= n + 1; i++)
		visit[i] = false;
}

int main()
{
	//freopen("in.txt", "r", stdin);

	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; i++){
		cin >> u >> v;
		g[u].push_back(v);
	}
	if (isCycle(1)){
		cout << "INFINITE PATHS" << endl;
	}
	
	else{
		init();
		cout << findWays(1) << endl;
	}

	return 0;
}