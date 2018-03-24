using namespace std;

#include <bits/stdc++.h>
#define si(x)       scanf("%d", &x)
#define sf          scanf
#define pf          printf
#define pb          push_back
#define N           105
#define M           10005

typedef long long int ll;

void hold()
{
    cout << "Press any key to contine......";
    getchar();
}

int main()
{
    int n, m, u, v, w, q, x, y, t, caseNo = 1, src;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    si(t);
    getchar();
    while(t--)
    {
        vector <int>graph[N];
        vector <int>cost[N];
        bool dp[N][M+5];
        si(n);
        si(m);
        si(q);
        getchar();
        //memset(graph, 0, sizeof(graph));
        memset(dp, false, sizeof(dp));
        for(int i = 0; i < m; i++)
        {
            si(u);
            si(v);
            si(w);
            getchar();
            graph[u].pb(v);
            graph[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        si(src);
        getchar();
        dp[src][0] = true;
        for(int time = 0; time < M; time++)
        {
            for(int u = 0; u < n; u++)
                if(dp[u][time])
                    for(int v = 0; v < graph[u].size(); v++)
                        if(time+cost[u][v] < M)
                            dp[graph[u][v]][time+cost[u][v]] = true;
            /*for(int u = 0; u < n; u++)
            {
                for(int t = 0; t <= time; t++)
                    pf("%d ",dp[u][t]);
                puts("");
            }
            hold();*/
        }
        pf("Case %d:\n", caseNo++);
        for(int i = 0; i < q; i++)
        {
            si(x);
            si(y);
            if(dp[x][y])
                pf("Yes\n");
            else
                pf("No\n");
        }
    }
    return 0;
}