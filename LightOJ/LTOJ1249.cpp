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
    int t, n, caseNo = 1, len, wid, hei, vol, maxi, mini;
    string str;
    si(t);
    while(t--)
    {
        si(n);
        maxi = INT_MIN;
        mini = INT_MAX;
        map <int, int> mm;
        map<string, int> sm;
        string str1;
        string str2;
        for(int i = 0; i < n; i++)
        {
            cin >> str >> len >> wid >> hei;
            vol = len*wid*hei;
            if(maxi < vol) {
                maxi = vol;
                str1 = str;
            }
            if(mini > vol) {
                mini = vol;
                str2 = str;
            }
        }
        pfc(caseNo++);
        if(maxi != mini)
            pf("%s took chocolate from %s\n", str1.c_str(), str2.c_str());
        else
            pf("no thief\n");
    }


    return 0;
}


