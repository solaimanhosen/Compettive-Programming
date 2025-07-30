#include <iostream>
#include <stdio.h>

using namespace std;

#define N 205

class Queue
{
	int myQueue[N];
	int f;
	int r;
public:
	Queue()
	{
		f = r = -1;
	}
	void push(int x)
	{
		if (f == -1 && r == -1){
			f = r = 0;
			myQueue[r] = x;
			return;
		}
		r = (r + 1) % N;
		myQueue[r] = x;
	}
	void pop()
	{
		if (f == r){
			f = r = -1;
			return;
		}
		f = (f + 1) % N;
	}
	int front()
	{
		return myQueue[f];
	}
	bool  empty()
	{
		if (f == -1 && r == -1)
			return true;
		return false;
	}
	void clear()
	{
		f = r = -1;
	}
};


int g[N][N];
int visit[N];
int color[N];
int n, m;
Queue q;

void init()
{
	for (int i = 0; i <= n + 1; i++){
		visit[i] = false;
		for (int j = 0; j <= n + 1; j++){
			g[i][j] = 0;
		}
	}
}

bool isBicolorable(int src)
{
	visit[src] = true;
	color[src] = 0;
	q.clear();
	q.push(src);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int v = 0; v < n; v++){
			if (g[u][v]){
				if (!visit[v]){
					visit[v] = true;
					color[v] = 1 - color[u];
					q.push(v);
				}
				else{
					if (color[u] == color[v])
						return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	//freopen("in.txt", "r", stdin);

	int u, v;
	
	while (cin >> n && n != 0){
		init();
		cin >> m;
		for (int i = 0; i < m; i++){
			cin >> u >> v;
			g[u][v] = 1;
			g[v][u] = 1;
		}
		
		if (isBicolorable(0)){
			cout << "BICOLORABLE." << endl;
		}
		else{
			cout << "NOT BICOLORABLE." << endl;
		}
	}



	return 0;
}