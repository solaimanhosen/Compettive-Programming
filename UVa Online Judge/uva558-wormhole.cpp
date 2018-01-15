#include <bits/stdc++.h>
#define MAX 2000

using namespace std;

struct graph
{
    int src;
    int des;
    int wei;
} ed[MAX+5];

int dis[1005];

bool BellmanFord(int node, int edge)
{
    int i , j;
    for(i = 0; i < node; i++)
        dis[i] = INT_MAX;
    dis[0] = 0;
    for(i = 0; i < node - 1; i++)
    {
        for(j = 0; j < edge; j++)
        {
            if(dis[ed[j].src] != INT_MAX && dis[ed[j].des] > dis[ed[j].src] + ed[j].wei)
            {
                dis[ed[j].des] = dis[ed[j].src] + ed[j].wei;
            }
        }
    }
    for(j = 0; j < edge; j++)
        if(dis[ed[j].des] > dis[ed[j].src] + ed[j].wei)
        {
            return true;
        }
    return false;
}

int main()
{
    int t, n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++)
            scanf("%d %d %d", &ed[i].src, &ed[i].des, &ed[i].wei);

        if(BellmanFord(n, m))
            printf("possible\n");
        else
            printf("not possible\n");
    }



    return 0;
}
