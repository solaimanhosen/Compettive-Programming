using namespace std;
#include <bits/stdc++.h>

#define pf          printf
#define sf          scanf
#define si(x)       sf("%d",&x)
#define si2(x,y)    sf("%d %d",&x,&y)
#define si3(x,y,z)  sf("%d %d %d",&x,&y,&z)
#define ss(x)       sf("%s",x)
#define pfc(x)      pf("Case %d: ",x)
#define pfcn(x)     pf("Case %d:\n",x)
#define pfv(x)      pf("%d\n",x)
#define pb          push_back
#define ll          long long
#define f           first
#define s           second
#define N           30005


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char main[100005];
    char sub[1005];
    int t, n;
    si(t);
    while(t--){
        cin >> main;
        si(n);
        for(int i = 1; i <= n; i++){
            cin >> sub;
            if(strstr(main, sub) != NULL)
                pf("y\n");
            else
                pf("n\n");
        }
    }


    return 0;
}


