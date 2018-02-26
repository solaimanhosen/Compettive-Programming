#include <bits/stdc++.h>

using namespace std;

char grid[101][101];
bool visit[101][101];
int dist[101][101];
int n;

struct node
{
    int x;
    int y;
};

node src, dest;

bool valid(node p)
{
    if(p.x >= 0 && p.x < n && p.y >= 0 && p.y < n)
        return true;
    return false;
}

void bfs()
{
    visit[src.x][src.y] = true;
    dist[src.x][src.y] = 0;
    queue<node>q;
    q.push(src);

    while(!q.empty()){
        src = q.front();
        q.pop();

        bool done = false;
        int x = src.x + 1;
        int y = src.y;
        while(!done && x < n){
            if(grid[x][y] != 'X' && !visit[x][y]){
                    q.push({x,y});
                    dist[x][y] = 1 + dist[src.x][src.y];
                    visit[x][y] = true;
            }
            else if(grid[x][y] == 'X')
                done = true;

            x++;
        }

        done = false;
        x = src.x - 1;
        y = src.y;
        while(!done && x >= 0){
            if(grid[x][y] != 'X' && !visit[x][y]){
                    q.push({x,y});
                    dist[x][y] = 1 + dist[src.x][src.y];
                    visit[x][y] = true;
            }
            else if(grid[x][y] == 'X')
                done = true;

            x--;
        }

        done = false;
        x = src.x;
        y = src.y + 1;
        while(!done && y < n){
            if(grid[x][y] != 'X' && !visit[x][y]){
                    q.push({x,y});
                    dist[x][y] = 1 + dist[src.x][src.y];
                    visit[x][y] = true;
            }
            else if(grid[x][y] == 'X')
                done = true;

            y++;
        }

        done = false;
        x = src.x;
        y = src.y - 1;
        while(!done && y >= 0){
            if(grid[x][y] != 'X' && !visit[x][y]){
                    q.push({x,y});
                    dist[x][y] = 1 + dist[src.x][src.y];
                    visit[x][y] = true;
            }
            else if(grid[x][y] == 'X')
                done = true;

            y--;
        }

    }

}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    cin >> src.x >> src.y >> dest.x >> dest.y;

    bfs();

    cout << dist[dest.x][dest.y] << endl;


    return 0;
}
