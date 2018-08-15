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
    int t, caseNo=1, r1,c1,r2,c2,min_move,dr,dc;

    sfi(t);
    while(t--){
        sfi2(r1,c1);
        sfi2(r2,c2);
        dr = abs(r2-r1);
        dc = abs(c2-c1);
        pfc(caseNo++);
        if((dr%2==0 && dc%2==1) || (dr%2==1 && dc%2==0))
            printf("impossible\n");
        else{
            if(dc == dr)
               printf("1\n");
            else
                printf("2\n");

        }
    }


    return 0;
}
