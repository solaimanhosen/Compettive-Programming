#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

#define M			505
#define INF			300009


int g[M][M];
bool visit[M];
int dist[M];
int t, m, n;

void init()
{
	
	for (int i = 0; i < M; i++)
	{
		visit[i] = false;
		dist[i] = INF;
		for (int j = 0; j < M; j++){
			g[i][j] = INF;
		}
	}
	
}


int max(int a, int b)
{
	if (a >= b)
		return a;
	return b;
}

void bfs(int src)
{
	queue<int>q;
	q.push(src);
	dist[src] = 0;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int v = 0; v < n; v++){
			if (g[u][v] != INF){
				int w = g[u][v];
				w = max(w, dist[u]);
				if (dist[v] > w)
				{
					dist[v] = w;
					q.push(v);
				}
					
			}
		}
	}

}



int main()
{
	//freopen("in.txt", "r", stdin);

	int u, v, w, src;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		init();
		scanf("%d %d", &n, &m);
		for (int j = 1; j <= m; j++){
			scanf("%d %d %d", &u, &v, &w);
			if (g[u][v] > w){
				g[u][v] = w;
				g[v][u] = w;
			}
			
		}
		
		scanf("%d", &src);
		bfs(src);

		printf("Case %d:\n", i);
		for (int j = 0; j < n; j++){
			if (dist[j] == INF){
				printf("Impossible\n");
			}
			else{
				printf("%d\n", dist[j]);
			}
			
		}
	}



	return 0;
}