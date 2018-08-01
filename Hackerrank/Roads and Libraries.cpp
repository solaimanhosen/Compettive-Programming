#include<bits/stdc++.h>
#define sf              scanf
#define pf              printf
#define sfi(n)          sf("%d", &n)
#define sfl(n)          sf("%lld", &n)
#define sfd(n)          sf("%lf", &n)
#define sfi2(x,y)       sf("%d %d", &x, &y);
#define sfl2(x,y)       sf("%lld %lld", &x, &y)
#define sfd2(x,y)       sf("%lf %lf", &x, &y)
#define pfc(i)          pf("Case %d: ", i)
#define pfn(n)          pf("%d\n", n)
#define pfln(n)         pf("%lld\n", n)
#define pfdn(n)         pf("%lf\n", n)
#define pb              push_back
#define bl              pf("\n")
#define spc             putchar(' ')
#define fli()           freopen("in.txt","r",stdin)
#define flo()           freopen("out.txt","w",stdout)
#define ll              long long
#define ull             unsigned long long
#define f               first
#define s               second
#define PI              acos(-1)
#define repe(i,n,test)  for(int i=n; i<=test; i++)
#define rep(i,n,test)   for(int i=n; i<test; i++)
#define MOD             1000000007
#define N               100007
#define pii             pair<int,int>
#define mp              make_pair

using namespace std;

vector<int>g[N];
bool visit[N];
int m, n, tl, tr;

void reset()
{
    tl = tr = 0;
    for(int i = 0; i <= m; i++){
        g[i].clear();
        visit[i] = false;
    }

}

int BFS(int src)
{
    visit[src] = true;
    queue<int>q;
    q.push(src);
    int road = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(!visit[v]){
                visit[v] = true;
                road++;
                q.push(v);
            }
        }
    }
    return road;
}

int main()
{
    //fli();

    ll q, cr, cl, total;
    cin >> q;
    while(q--){
        cin >> m >> n >> cl >> cr;
        reset();
		int u, v;
        for(int i = 1; i <= n; i++){
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        if(cr > cl){
            pf("%lld\n", m*cl);
        }
        else
        {
            for(int i = 1; i <= m; i++){
                if(!visit[i]){
                    tl++;
                    tr += BFS(i);
                }
            }
            pf("%lld\n",tl*cl+tr*cr);
        }

    }


    return 0;
}




