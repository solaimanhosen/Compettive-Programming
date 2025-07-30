#include <bits/stdc++.h>
#define N 40000
#define pf(x) printf("%d\n", x)
#define sf(x) scanf("%d", &x)
#define cpf(x) printf("Case %d: ",  x)
#define pb(x) push_back(x)
#define vi vector <int>
#define qi queue <int>
#define mem(x) memset(x, 0, sizeof(x)))



using namespace std;

bool BFS(vi g[])
{
    qi q;
    int color[N], i, x;
    memset(color, -1, sizeof(color));
    q.push(0);
    color[0] = 1;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        for(i = 0; i < g[x].size(); i++)
        {
            if(color[g[x][i]] == -1)
            {
                color[g[x][i]] = 1 - color[x];
                q.push(g[x][i]);
            }
            else if(color[g[x][i]] == color[x])
                return false;
        }
    }
    return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int node, edge, i, j, x, y;
    while(sf(node))
    {

        if(!node)
            return 0;
        else
        {
            sf(edge);
            vi g[N];
            for(i = 1; i <= edge; i++)
            {
                sf(x);
                sf(y);
                g[x].pb(y);
                g[y].pb(x);
            }
            if(BFS(g))
                puts("BICOLORABLE.");
            else
                puts("NOT BICOLORABLE.");
        }
    }


    return 0;
}
