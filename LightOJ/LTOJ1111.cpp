using namespace std;

#include <bits/stdc++.h>
#define sf              scanf
#define si(x)           scanf("%d", &x)
#define sl(x)           scanf("%lld", &x)
#define ss(x)           scanf("%s", x)
#define pf              printf
#define pb              push_back
#define N               1000
#define PI              3.40954185
#define F               first
#define S               second


typedef long long int ll;


vector<int> graph[N+5];
int dist[N+5];
bool visit[N+5];

void bfs(int src)
{
    visit[src] = true;
    dist[src]++;
    int u, v;
    queue<int>q;
    q.push(src);

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i = 0; i < graph[u].size(); i++)
        {
            //puts("working");
            v = graph[u][i];
            if(!visit[v])
            {
                q.push(v);
                visit[v] = true;
                dist[v]++;
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
   int t, k, n, m, i, j, caseNo = 1, x, u, v;
   si(t);
   while(t--)
   {
       vector <int> p;
       memset(dist, 0, sizeof(dist));

       for(i = 0; i<= N; i++)
            graph[i].clear();

       si(k);
       si(n);
       si(m);

       for(i = 1; i <= k; i++)
       {
           si(x);
           p.pb(x);
       }
       for(i = 1; i <= m; i++)
       {
           si(u);
           si(v);
           graph[u].pb(v);
       }
       for(i = 0; i < p.size(); i++)
       {
           memset(visit, false, sizeof(visit));
           bfs(p[i]);
       }
       int cnt = 0;
       for(i = 1; i<= n; i++)
       {
           if(dist[i] == k)
                cnt++;
       }
       pf("Case %d: %d\n", caseNo++, cnt);
   }


    return 0;
}



