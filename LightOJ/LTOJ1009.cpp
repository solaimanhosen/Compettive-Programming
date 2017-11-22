using namespace std;

#include <bits/stdc++.h>
#define sf              scanf
#define si(x)           scanf("%d", &x)
#define sl(x)           scanf("%lld", &x)
#define pf              printf
#define pfc(x)          pf("Case %d: ", x)
#define pfv(x)          pf("%d\n", x)
#define pb              push_back
#define N               20010
#define PI              3.40954185
#define F               first
#define S               second
#define pii             pair <int, int>

vector < int > graph[N];
bool visit[N];
int vam;
int lyc;

void bfs(int s)
{
    vam++;
    visit[s] = true;
    pii src, temp;
    queue < pii > q;
    q.push({s,0});

    while(!q.empty()){
        src = q.front();
        q.pop();
        for(int i = 0; i < graph[src.F].size(); i++){
            int v = graph[src.F][i];
            if(!visit[v] && !src.S)
            {
                visit[v] = true;
                lyc++;
                q.push({v,1});
            }
            if(!visit[v] && src.S)
            {
                visit[v] = true;
                vam++;
                q.push({v,0});
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, n, u, v, caseNo = 1, ans;

    si(t);
    while(t--){
        si(n);
        for(int i = 0; i < N; i++)
            graph[i].clear();

        for(int i = 1; i <= n; i++){
            si(u);si(v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        ans = 0;
        memset(visit, false, sizeof(visit));

        for(int i = 1; i < N; i++){
            if(graph[i].size() != 0 && !visit[i]){
                vam = 0;
                lyc = 0;
                bfs(i);
                ans += max(vam,lyc);
            }
        }
        pfc(caseNo++);
        pfv(ans);
    }

    return 0;
}
