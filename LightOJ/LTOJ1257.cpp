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
#define N           30005

vector< pair<int, int> > graph[N+5];
bool visit[N+5];
int dist[N+5];
int d[N+5];

void BFS(int src)
{
    dist[src] = 0;
    visit[src] = true;
    pair < int , int> pp;
    queue < int > q;
    q.push(src);

    while(!q.empty())
    {
        src = q.front();
        q.pop();
        for(int i = 0; i < graph[src].size(); i++){
            pp = graph[src][i];
            if(!visit[pp.f]){
                dist[pp.f] = dist[src] + pp.s;
                q.push(pp.f);
                visit[pp.f] = true;
            }
        }
    }
}

void BFS2(int src)
{
    d[src] = 0;
    visit[src] = true;
    pair < int , int> pp;
    queue < int > q;
    q.push(src);

    while(!q.empty())
    {
        src = q.front();
        q.pop();
        for(int i = 0; i < graph[src].size(); i++){
            pp = graph[src][i];
            if(!visit[pp.f]){
                d[pp.f] = d[src] + pp.s;
                q.push(pp.f);
                visit[pp.f] = true;
            }
        }
    }
}

int main()
{
    int t, n, u, v, w, caseNo = 1, max_len, max_node;
    si(t);
    while(t--)
    {
        si(n);
        for(int i = 0; i <= n; i++)
            graph[i].clear();
        for(int i = 1; i < n; i++)
        {
            si3(u, v, w);
            graph[u].pb(make_pair(v,w));
            graph[v].pb(make_pair(u,w));
        }
        max_len = -1;
        fill(visit, visit+n+5, false);
        fill(dist, dist+n+5, 0);
        BFS(0);

        for(int i = 0; i < n; i++){
            if(max_len < dist[i]){
                max_len = dist[i];
                max_node = i;
            }
        }
        max_len = -1;
        fill(visit, visit+n+5, false);
        fill(dist, dist+n+5, 0);
        BFS(max_node);

        for(int i = 0; i < n; i++){
            if(max_len < dist[i]){
                max_len = dist[i];
                max_node = i;
            }
        }

        max_len = -1;
        fill(visit, visit+n+5, false);
        fill(d, d+n+5, 0);
        BFS2(max_node);

        pfcn(caseNo++);

        for(int i = 0; i < n; i++)
            pfv(max(dist[i], d[i]));
        //pfv(max_len);
    }


    return 0;
}

