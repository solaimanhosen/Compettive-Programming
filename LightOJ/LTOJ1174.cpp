#include <bits/stdc++.h>

using namespace std;

#define pf          printf
#define sf          scanf
#define si(x)       sf("%d",&x)
#define si2(x,y)    sf("%d %d",&x,&y)
#define si3(x,y,z)  sf("%d %d %d",&x,&y,&z)
#define pfc(x)      pf("Case %d: ",x)
#define pfcn(x)     pf("Case %d:\n",x)
#define pfv(x)      pf("%d\n",x)
#define pb          push_back
#define f           first
#define s           second
#define N           105

vector <int> graph[N];
bool visit[N];
int dist[N];

int BFS(int s, int d)
{
    if(s == d)
        return 0;

    memset(visit, false, sizeof(visit));
    memset(dist, 0, sizeof(dist));

    visit[s] = true;
    dist[s] = 0;
    queue <int> q;
    q.push(s);

    while(!q.empty()){
        int src = q.front();
        q.pop();
        for(int i = 0; i < graph[src].size(); i++){
            int adj = graph[src][i];
            if(!visit[adj]){
                visit[adj] = true;
                dist[adj] = dist[src] + 1;
                q.push(adj);
                if(d == adj)
                    return dist[adj];
            }
        }
    }
    return 0;
}


int main()
{
    int t, n, r, i, j, u, v, caseNo = 1, mx, s, d;
    si(t);
    while(t--){
        si(n);
        si(r);

        for(i = 0; i<= n; i++)
            graph[i].clear();

        for(i = 1; i <= r; i++){
            si2(u,v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        si2(s,d);

        mx = 0;

        for(i = 0; i < n; i++){
            mx = max(mx, BFS(s, i)+BFS(i, d));
        }
        pfc(caseNo++);
        pfv(mx);
    }




    return 0;
}

