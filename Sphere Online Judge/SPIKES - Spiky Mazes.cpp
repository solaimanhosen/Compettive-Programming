#include <iostream>
#include <stdio.h>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX			45

struct pair_pair
{
	int x;
	int y;
	int prior;
	bool operator < (const pair_pair& t2) const
	{
		if (prior < t2.prior)
			return true;
		return false;
	}
};

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

char grid[MAX][MAX];
bool visit[MAX][MAX];
int n, m, j;

bool isValid(int x, int y)
{
	if (x <= 0 || x > n || y <= 0 || y > m)
		return false;
	if (grid[x][y] == '#'){
		return false;
	}
	return true;
}

int BFS(pair_pair src, int spike)
{
	priority_queue<pair_pair>q;
	src.prior = spike;
	q.push(src);
	visit[src.x][src.y] = true;
	while (!q.empty()){
		src = q.top(); q.pop();
		pair_pair temp;
		for (int i = 0; i < 4; i++){
			temp.x = src.x + dx[i];
			temp.y = src.y + dy[i];

			if (isValid(temp.x, temp.y) && !visit[temp.x][temp.y]){
				if (grid[temp.x][temp.y] == 's'){
					if (src.prior - 1 >= 0){
						temp.prior = src.prior - 1;
						q.push(temp);
						visit[temp.x][temp.y] = true;
					}
				}
				else if (grid[temp.x][temp.y] == '.'){
					temp.prior = src.prior;
					q.push(temp);
					visit[temp.x][temp.y] = true;
				}
				else if (grid[temp.x][temp.y] == '@'){
					return src.prior;
				}
			}
		}
	}
	return -1;
}

int main()
{
	//freopen("in.txt", "r", stdin);

	cin >> n >> m >> j;

	pair_pair src;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> grid[i][j];
			if (grid[i][j] == 'x'){
				src = { i, j };
			}
		}
	}

	int mini = BFS(src, j);
	if (mini == -1 || (j - mini) * 2 > j){
		cout << "IMPOSSIBLE" << endl;
	}
	else{
		cout << "SUCCESS" << endl;
	}

	return 0;
}
