using namespace std;

#include <bits/stdc++.h>
#define si(x)       scanf("%d", &x)
#define sif(x)      scanf("%d", &x);getchar()
#define sl(x)       scanf("%lld", &x)
#define sf          scanf
#define pf          printf
#define pb          push_back
#define N           3005
#define M           1000000007
#define INF         INT_MIN;

typedef long long int ll;

int graph[N][N];
int dist[N][N];

int n, t;

void hold()
{
    cout <<"Press any key to continue.....";
    getchar();
}

int main()
{
    int i, j, k, caseNo = 1, u, v, w;
    sif(t);
    while(t--)
    {
        sif(n);
        hold();
        for(u = 0; u < n; u++)
            for(v = 0; v < n; v++)
            {
                if(u == v)
                    graph[u][v] = 0;
                else
                    graph[u][v] = INF;
            }
        hold();
        for(i = 0; i < n-1; i++)
        {
            si(u);
            si(v);
            sif(w);
            graph[u][v] = w;
            graph[v][u] = w;
        }
        hold();
        for(u = 0; u < n; u++)
        {
            for(v = 0; v < n; v++)
            {
                dist[u][v] = graph[u][v];
                pf("%d ", dist[u][v]);
            }
            pf("\n");
        }
        hold();

        for(k = 0; k < n; k++)
            for(u = 0; u < n; u++)
                for(v = 0; v < n; v++)
                    if(dist[u][v] < dist[u][k]+dist[k][v])
                        dist[u][v] = dist[u][k]+dist[k][v];
        int maxi = INF;
        for(u = 0; u < n; u++)
            for(v = 0; v < n; v++)
                if(dist[u][v] > maxi)
                    maxi = dist[u][v];
        pf("Case %d: %d\n", caseNo++, maxi);
    }

    return 0;
}



