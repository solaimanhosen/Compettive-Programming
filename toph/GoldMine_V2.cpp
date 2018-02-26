#include <bits/stdc++.h>
#define sf     scanf
#define pf     printf
#define si(x)  scanf("%d", &x)
#define pfi(x) printf("%d\n", x)
#define pfc(x) printf("Case %d: ", x)
#define pb     push_back
#define N      41

using namespace std;

struct pair_pair
{
    int x;
    int y;
};

typedef long long int ll;
typedef struct pair_pair pp;

char grid[N][N];
int mine_num[N], n, m;
int visit[N][N];
int mine_id[N][N];
int dist[N][N];
int id, mini;

int dx[] = {0,0,1,-1,-1,1,-1,1};
int dy[] = {1,-1,0,0,-1,1,1,-1};

int DFS(int p, int q)
{
    mine_id[p][q] = id;
    int cnt = 1;
    for(int i = 0; i < 8; i++)
    {
        int a, b;
        a = p+dx[i];
        b = q+dy[i];
        if(a < 0 || b < 0 || a > n-1 || b > m-1)
            continue;
        if(grid[a][b] == 'G' && mine_id[a][b] == 0)
        {
            cnt += DFS(a, b);
        }

    }
    return cnt;
}

void BFS(pp src, int par_id)
{
    queue < pp > Q;
    int i, j;
    pp temp;
    Q.push(src);
    visit[src.x][src.y] = 1;
    dist[src.x][src.y] = 0;
    while(!Q.empty())
    {
        src = Q.front();
        Q.pop();
        for(int i = 0; i < 8; i++)
        {
            int a = src.x+dx[i];
            int b = src.y+dy[i];
            if(a < 0 || b < 0 || a > n-1 || b > m-1)
                continue;
            if(mine_id[a][b] == 0 && !visit[a][b])
            {
                visit[a][b] = 1;
                dist[a][b] = dist[src.x][src.y] + 1;
                temp.x = a;
                temp.y = b;
                Q.push(temp);
            }
            else if(mine_id[a][b] != par_id && !visit[a][b])
            {
                mini = min(mini, mine_num[par_id]*dist[src.x][src.y]*mine_num[mine_id[a][b]]);
                visit[a][b] = 1;
            }
        }
    }
}

int main()
{
    int t, caseNo = 1, i, j;
    pp mn;
    si(t);
    getchar();
    while(t--)
    {
        si(n);
        getchar();
        si(m);
        getchar();
        vector < pp > v;
        for(i = 0; i < n; i++)
        {
            gets(grid[i]);
            for(j = 0; j < m; j++)
            {
                if(grid[i][j] == 'G')
                {
                    mn.x = i;
                    mn.y = j;
                    v.pb(mn);
                }
            }
        }
        memset(mine_id, 0, sizeof(mine_id));
        id = 1;
        for(i = 0; i < v.size(); i++)
            if(mine_id[v[i].x][v[i].y] == 0)
            {
                int cnt = DFS(v[i].x, v[i].y);
                mine_num[id] = cnt;
                id++;
            }

        if(id < 3) printf("Case %d: -1\n",caseNo++);
        else
        {
            mini = INT_MAX;
            for(i = 0; i < v.size(); i++)
                if(!visit[v[i].x][v[i].y])
                {
                    BFS(v[i],mine_id[v[i].x][v[i].y]);
                    memset(visit, 0, sizeof(visit));
                }
            pfc(caseNo++);
            pfi(mini);
        }
    }

    return 0;
}
