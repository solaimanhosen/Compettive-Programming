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
#define debug(x)        cout << "#x: " << " " << x << endl;
#define MOD             1000000007
#define N               100

using namespace std;

vector <int> g[10009];
bool visit[10009];
int n, m;
int has[10009], sum, nc;

void bfs(int src)
{
    visit[src] = true;
    sum += has[src];
    nc++;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int src = q.front();
        q.pop();
        for(int i = 0; i < g[src].size(); i++){
            int v = g[src][i];
            if(visit[v] == false){
                visit[v] = true;
                sum += has[v];
                nc++;
                q.push(v);
            }
        }
    }
}


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, caseNo = 1, u, v, money = -1;
    bool flag = true;
    sfi(t);
    while(t--){
        money = -1;
        sfi2(n,m);
        repe(i,1,n){
            g[i].clear();
            visit[i] = false;
            sfi(has[i]);
        }
        repe(i,1,m){
            sfi2(u,v);
            g[u].pb(v);
            g[v].pb(u);
        }
        pfc(caseNo++);
        flag = true;
        repe(i,1,n){
            nc = 0;
            sum = 0;
            if(visit[i] == false){
                bfs(i);

                if(sum % nc != 0){
                    flag = false;
                    break;
                }
                if(money == -1){
                    money = sum/nc;
                }
                else if(money != sum/nc){
                        flag = false;
                        break;
                }
            }

        }
        if(flag)
            pf("Yes\n");
        else
            pf("No\n");
    }


    return 0;
}


