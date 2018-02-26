#include<bits/stdc++.h>
#define M 55
using namespace std;
int dx[]= {0,1,0,-1};
int dy[]= {1,0,-1,0};
vector<int>Ans;
int id=0;
char str[M][M];
int ID[M*M],pic[M][M];
bool dfs(int x,int y)
{
    if(!str[x][y])return false;
    if(str[x][y]=='*'||pic[x][y])return true;
    pic[x][y]=id;
    ID[id]++;
    bool f=true;
    for(int d=0; d<4; d++)
    {
        int nx=x+dx[d],ny=y+dy[d];
        f&=dfs(nx,ny);
    }
    return f;
}
bool cmp(int a,int b)
{
    return ID[a]<ID[b];
}
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1; i<=n; i++)
        scanf("%s",str[i]+1);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(str[i][j]=='.'&&!pic[i][j])
            {
                ++id;
                if(dfs(i,j))Ans.push_back(id);
            }
    sort(Ans.begin(),Ans.end(),cmp);
    int sz=Ans.size()-k;
    int cnt=0;
    for(int i=0; i<sz; i++)
    {
        int now=Ans[i];
        for(int x=1; x<=n; x++)
            for(int y=1; y<=m; y++)
                if(pic[x][y]==now)str[x][y]='*',cnt++;
    }
    printf("%d\n",cnt);
    for(int i=1; i<=n; i++)puts(str[i]+1);
}
