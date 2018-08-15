#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define MAX			100005
#define ll			long long

int n, p;
ll counter;

//int graph[MAX][MAX];
vector<int>graph[MAX];
bool visit[MAX];

template<class T>class Queue
{
	T myQueue[MAX];
	int f, r, length;
public:
	Queue(){ f = r = -1; length = 0; }
	void push(T data){
		if (r == -1 && f == -1){
			f = r = 0;
			myQueue[r] = data;
			length++;
			return;
		}
		r = (r + 1) % MAX;
		myQueue[r] = data;
		length++;
	}
	void pop()
	{
		if (f == r){
			f = r = -1;
			length = 0;
			return;
		}
		f = (f + 1) % MAX;
		length--;
	}
	bool empty()
	{
		if (f == -1 && r == -1)
			return true;
		return false;
	}
	T front()
	{
		return myQueue[f];
	}
};


int bfs(int src)
{
	int c = 1;
	visit[src] = true;
	Queue<int>q;
	q.push(src);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int i = 0; i < graph[u].size(); i++){
			int v = graph[u][i];
			if (!visit[v]){
				c++;
				visit[v] = true;
				q.push(v);
			}
		}
	}
	return c;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	
	int u, v;
	scanf("%d %d", &n, &p);

	for (int i = 1; i <= p; i++){
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	counter = 0;
	vector<int>tree;
	for (int i = 0; i < n; i++){
		if (!visit[i]){
			tree.push_back(bfs(i));
		}
	}
	ll cum = 0;
	for (int i = 0; i < tree.size(); i++){
			counter += (cum * tree[i]);
			cum += tree[i];
	}
	printf("%lld\n", counter);


	return 0;
}