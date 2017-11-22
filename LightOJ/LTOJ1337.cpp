using namespace std;
#include <bits/stdc++.h>

#define pf          printf
#define sf          scanf
#define si(x)       sf("%d",&x)
#define si2(x,y)    sf("%d %d",&x,&y)
#define si3(x,y,z)  sf("%d %d %d",&x,&y,&z)
#define pfc(x)      pf("Case %d: ",x)
#define pfcn(x)     pf("Case %d:\n",x)
#define pfv(x)      pf("%d\n",x)
#define pb          push_back
#define ll          long long
#define f           first
#define s           second
#define N           505

char grid[N][N];
bool visit[N][N];
int ids[N][N];
int crystal[N*N];
int id, row, col;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool valid(int x, int y)
{
    if(x >= 1 && x <= row && y >= 1 && y <= col)
        return true;
    return false;
}

int BFS(int x, int y)
{
    int mx = 0;
    visit[x][y] = true;
    ids[x][y] = id;
    queue < pair<int, int> > q;
    pair <int, int> pp;
    q.push(make_pair(x,y));

    while(!q.empty()){
        pp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            x = pp.f+dx[i];
            y = pp.s+dy[i];
            if(!visit[x][y] && valid(x,y) && grid[x][y] != '#'){
                visit[x][y] = true;
                ids[x][y] = id;
                q.push(make_pair(x,y));
                if(grid[x][y] == 'C')
                    mx++;
            }
        }
    }
    return mx;
}


int main()
{
    int t, caseNo = 1, q, x, y;
    si(t);
    while(t--){
        si3(row,col,q);
        for(int i = 1; i <= row; i++)
            sf("%s",grid[i]+1);

        memset(ids, 0, sizeof(ids));
        memset(crystal, 0, sizeof(crystal));
        memset(visit, false, sizeof(visit));
        id = 0;

        for(int i = 1; i <= row; i++)
            for(int j = 1; j <= col; j++)
                if(!visit[i][j] && grid[i][j] == '.'){
                    id++;
                    crystal[id] = BFS(i,j);
                }
        pfcn(caseNo++);
        for(int i = 1; i <= q; i++){
            si2(x,y);
            pfv(crystal[ids[x][y]]);
        }
    }
    return 0;
}
