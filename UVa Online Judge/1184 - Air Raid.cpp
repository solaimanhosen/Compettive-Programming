#include <iostream>
#define N			130

using namespace std;

//vector<int>g[N];
int g[N][N];
int match[N];
bool visit[N];
int n, e;

int bpm(int u)
{
	for (int v = 1; v <= n; v++){
		if (g[u][v] && !visit[v]){
			visit[v] = true;
			if (match[v] == -1 || bpm(match[v])){
				match[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

void init(int n)
{
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			g[i][j] = 0;
		match[i] = -1;
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase, u, v;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++){
		cin >> n >> e;
		init(n);
		for (int i = 1; i <= e; i++){
			cin >> u >> v;
			g[u][v] = 1;
		}
		int MBPM = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++)
				visit[j] = false;
			if (bpm(i)){
				MBPM++;
			}
			
		}
		cout << n - MBPM << endl;
	}



	return 0;
}