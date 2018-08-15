#include <cstdio>

int n,m,a[50][50];

int check(int x,int y)
{
    for(int i=1; i<=n; i++)
    {
        int t,f=0;
        for(int j=1; j<=m; j++)
        {
            t=a[i][j];
            if(j==x)t=a[i][y];
            if(j==y)t=a[i][x];
            if(t!=j)f++;
        }
        if(f!=0&&f!=2)return 0;
    }
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d",&a[i][j]);
    for(int i=1; i<=m; i++)
        for(int j=1; j<=i; j++)
        {
            if(check(i,j))
            {
                puts("YES");
                return 0;
            }
        }
    puts("NO");
    return 0;
}
