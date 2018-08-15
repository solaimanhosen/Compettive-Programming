#include <iostream>
#include <sstream>
#include <stdio.h>
#include <map>
#include <queue>
#include <string.h>

using namespace std;

#define MAX         505

char grid[MAX][MAX];
int dp[MAX][MAX];
bool visit[MAX][MAX];
int n, m;

int toInt(char ch)
{
    return (int)(ch-'0');
}

struct pair_pair
{
    int x;
    int y;
};

bool isValid(int x, int y)
{
    if(x < 0 || y < 0 || x >= n || y >= m)
        return false;
    return true;
}

int BFS(int x, int y)
{
    dp[x][y] = 0;
    queue<pair_pair> q;
    q.push({x,y});
    visit[x][y] = true;
    pair_pair pp;
    while(!q.empty()){
        pp = q.front();q.pop();
        int xx = toInt(grid[pp.x][pp.y]);
        int tx, ty;

        tx = pp.x - xx;
        ty = pp.y;
        if(isValid(tx, ty) && !visit[tx][ty]){
            dp[tx][ty] = 1 + dp[pp.x][pp.y];
            q.push({tx, ty});
            visit[tx][ty] = true;
        }

        tx = pp.x + xx;
        ty = pp.y;
        if(isValid(tx, ty) && !visit[tx][ty]){
            dp[tx][ty] = 1 + dp[pp.x][pp.y];
            q.push({tx, ty});
            visit[tx][ty] = true;
        }

        tx = pp.x;
        ty = pp.y - xx;
        if(isValid(tx, ty) && !visit[tx][ty]){
            dp[tx][ty] = 1 + dp[pp.x][pp.y];
            q.push({tx, ty});
            visit[tx][ty] = true;
        }

        tx = pp.x;
        ty = pp.y + xx;
        if(isValid(tx, ty) && !visit[tx][ty]){
            dp[tx][ty] = 1 + dp[pp.x][pp.y];
            q.push({tx, ty});
            visit[tx][ty] = true;
        }
    }
    return dp[n-1][m-1];
}

int main()
{
    //freopen("in.txt", "r", stdin);


    string str;
    getline(cin , str);
    stringstream ss(str);
    ss >> n;
    ss >> m;
    //cout << n << " "<<  m << endl;
    for(int i = 0; i < n; i++){
        fgets(grid[i], sizeof(grid[i]), stdin);
    }
    int ans =  BFS(0, 0);
    cout << (ans?ans:-1) << endl;

    return 0;
}

