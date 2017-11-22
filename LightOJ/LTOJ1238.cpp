using namespace std;

#include <bits/stdc++.h>
#define sf              scanf
#define si(x)           scanf("%d", &x)
#define sl(x)           scanf("%lld", &x)
#define ss(x)           scanf("%s", x)
#define pf              printf
#define pb              push_back
#define N               25
#define PI              3.40954185
#define F               first
#define S               second

struct point
{
    int x;
    int y;
};


typedef long long int ll;
typedef struct point intPoint;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

char str[N][N];
bool visit[N][N];
bool res[3];
int d[3];
int grid[N][N];
int m, n;

bool valid(int x, int y)
{
    if(x >= 0 && x < m && y >= 0 && y <n)
        return true;
    return false;
}

void bfs(intPoint src)
{
    visit[src.x][src.y] = true;
    grid[src.x][src.y] = 0;
    intPoint p1, p2;
    queue <intPoint> q;
    q.push(src);

    while(!q.empty())
    {
        src = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            p1.x = src.x + dx[i];
            p1.y = src.y + dy[i];
            if(valid(p1.x, p1.y) && !visit[p1.x][p1.y] && str[p1.x][p1.y] != 'm' && str[p1.x][p1.y] != '#')
            {
                grid[p1.x][p1.y] = grid[src.x][src.y] + 1;
                visit[p1.x][p1.y] = true;
                q.push(p1);
                if(str[p1.x][p1.y] == 'a')
                {
                    d[0] = grid[p1.x][p1.y];
                    res[0] = true;
                }
                if(str[p1.x][p1.y] == 'b')
                {
                    d[1] = grid[p1.x][p1.y];
                    res[1] = true;
                }
                if(str[p1.x][p1.y] == 'c')
                {
                    d[2] = grid[p1.x][p1.y];
                    res[2] = true;
                }
                if(res[0] && res[1] && res[2])
                    return;
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int t, i, j, caseNo = 1;
    intPoint p;

    si(t);

    while(t--)
    {
        si(m);
        si(n);

        for(i = 0; i < m; i++)
            ss(str[i]);

        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                if(str[i][j] == 'h')
                {
                    memset(res, false, sizeof(res));
                    memset(visit, false, sizeof(visit));
                    memset(grid, 0, sizeof(grid));

                    p.x = i;
                    p.y = j;
                    bfs(p);
                }
        sort(d, d+3);
        pf("Case %d: %d\n", caseNo++, d[2]);
    }


    return 0;
}



