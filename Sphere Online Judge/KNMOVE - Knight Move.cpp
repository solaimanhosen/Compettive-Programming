#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize ("-Ofast")
#define fli()           freopen("in.txt", "r", stdin)
#define ll              long long int
#define MAX             1005
#define pii             pair<int,int>

int dx[] = {-2, -2, 2, 2, -1, 1, -1, 1};
int dy[] = {-1, 1, -1, 1, -2, -2, 2, 2};

int grid[MAX][MAX];
bool visit[MAX][MAX];

bool valid(int x, int y)
{
    if(x>= 1 && x <= 1000 && y >= 1 && y <= 1000){
        return true;
    }
    return false;
}

void BFS(int x, int y)
{
    queue<pii>q;
    grid[x][y] = 0;
    visit[x][y] = true;
    q.push({x, y});
    while(!q.empty()){
        pii src = q.front();
        q.pop();
        for(int i = 0; i < 8; i++){
            int tx = src.first + dx[i];
            int ty = src.second + dy[i];
            if(!visit[tx][ty] && valid(tx, ty)){
                grid[tx][ty] = 1 + grid[src.first][src.second];
                q.push({tx, ty});
                visit[tx][ty] = true;
            }
        }
    }
}

int main()
{
    //fli();
    BFS(1, 1);
    int t, x, y;
    cin >> t;
    while(t--){
        cin >> x >> y;
        cout << grid[x][y] << endl;
    }

    return 0;
}
