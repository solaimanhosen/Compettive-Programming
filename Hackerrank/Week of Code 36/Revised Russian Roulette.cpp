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
#define N               10005

using namespace std;


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, door, mini, maxi;
    mini = maxi = 0;
    bool flag = false;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> door;
        if(door == 1){
            maxi++;
            if(!flag){
                mini++;
                flag = true;
            }
            else{
                flag = false;
            }
        }
        else
            flag = false;

    }
    cout << mini << " " << maxi << endl;




    return 0;
}



