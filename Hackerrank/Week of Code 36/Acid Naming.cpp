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
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int testCase;
    string acidName;

    cin >> testCase;
    while(testCase--){
        cin >> acidName;
        if(acidName.length() >= 7 && !acidName.compare(0,5,"hydro") && !acidName.compare(acidName.size()-2,2,"ic"))
            cout << "non-metal acid" << endl;
        else if(!acidName.compare(acidName.size()-2,2,"ic"))
            cout << "polyatomic acid" << endl;
        else
            cout << "not an acid" << endl;
    }




    return 0;
}


