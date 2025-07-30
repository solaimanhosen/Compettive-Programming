#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>

#define N           20

using namespace std;

bool visit[N];
vector<int>g[N];
int n, s, p;

void init()
{
	for (int i = 0; i < N; i++){
		visit[i] = false;
		g[i].clear();
	}
}

int solve(int taken)
{
	if (taken == n){
		int counter = 0;
		for (int i = 0; i < n; i++){
			if (visit[i]) counter++;
		}
		if (counter == s){
			for (int i = 0; i < n; i++){
				int adj = 0;
				if (!visit[i]){

					for (int j = 0; j < g[i].size(); j++){
						adj += visit[g[i][j]];
					}
				}
				if (adj >= 2)
					return 0;
			}
			return 1;
		}
		return 0;
	}
	int res = 0;
	visit[taken] = false;
	res += solve(taken + 1);
	visit[taken] = true;
	res += solve(taken + 1);
	return res;
}

int main()
{
	//freopen("in.txt", "r", stdin);

	char str[20];
	char ed[3];
	while (cin >> str){
		if (strcmp(str, "TheEnd") == 0){
			printf("%s\n", str);
			break;
		}
		scanf("%d %d %d", &n, &s, &p);
		init();
		for (int i = 1; i <= p; i++){
			scanf("%s", ed);
			int u = (int)(ed[0] - 'A');
			int v = (int)(ed[1] - 'A');
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int res = 0;
		res += solve(0);
		printf("%s\n", str);
		printf("%d\n", res);
	}



	return 0;
}
