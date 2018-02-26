#include<cstdio>
#include<algorithm>
using namespace std;
const int N=21;
int n,m,x,y,i,j,a[N][N];
bool pd()
{
    for (int i=1; i<=n; i++)
    {
        int k=0;
        for (int j=1; j<=m; j++)
            if (a[i][j]!=j)
            {
                k++;
                if (k>2) return 0;;
            }
    }
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            scanf("%d",&a[i][j]);
    if (pd())
        return puts("YES"),0;
    for(x=1; x<m; x++)
        for (y=x+1; y<=m; y++)
        {
            for (i=1; i<=n; i++)
                swap(a[i][x],a[i][y]);
            if (pd())
                return puts("YES"),0;
            for (i=1; i<=n; i++)
                swap(a[i][x],a[i][y]);
        }
    puts("NO");
}
