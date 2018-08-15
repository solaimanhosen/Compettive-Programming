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
#define N               100

using namespace std;


int main()
{
    //fli();
    //flo();
    int t, area, Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;

    sfi(t);
    repe(i,1,t)
    {
        scanf("%d %d",&Ax,&Ay);
        scanf("%d %d",&Bx,&By);
        scanf("%d %d",&Cx,&Cy);

        Dx = Ax + (Cx - Bx);
        Dy = Cy + (Ay - By);

        area = abs((Ax*By+Bx*Cy+Cx*Dy+Dx*Ay)-(Ay*Bx+By*Cx+Cy*Dx+Dy*Ax));
        area = 0.5*area;

        pfc(i);
        pf("%d %d %d\n",Dx,Dy,area);
    }




















    return 0;
}
