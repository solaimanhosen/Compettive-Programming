#include<bits/stdc++.h>
#define sfi(n) scanf("%d", &n)
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pf(n) printf("%d", n)
#define pfc(i) printf("Case %d: ", i)
#define pfn(n) printf("%d\n", n)
#define pfdn(n) printf("%f\n", n)
#define pb push_back
#define bl printf("\n")
#define spc putchar(' ')
#define fli() freopen("in.txt","r",stdin)
#define flo() freopen("out.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define f   first
#define s   second
#define debug(x) cerr << #x << " : " << x << endl
#define find puts("I am here")
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
#define N   100

using namespace std;


int main()
{
    //fli();
    int n, t, caseNo = 1, x1, x2, y1, y2, z1, z2, xmin, xmax, ymin, ymax, zmin, zmax;

    sfi(t);
    while(t--)
    {
        xmin = ymin = zmin = 0;
        xmax = ymax = zmax = 10001;
        sfi(n);
        for(int i = 1; i <= n; i++){
            scanf("%d %d %d %d %d %d", &x1,&y1,&z1,&x2,&y2,&z2);
            xmin = max(xmin, x1);
            xmax = min(xmax, x2);
            ymin = max(ymin, y1);
            ymax = min(ymax, y2);
            zmin = max(zmin, z1);
            zmax = min(zmax, z2);
        }
        int volume = (xmax-xmin)*(ymax-ymin)*(zmax-zmin);
        printf("Case %d: %d\n",caseNo++, volume < 0? 0:volume);
    }


    return 0;
}
