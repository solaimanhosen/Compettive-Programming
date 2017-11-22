
#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 165000

using namespace std;

typedef long long int ll;

int main()
{
    string comm, curr;
    int t;
    si(t);
    for(int i = 1; i <= t; i++)
    {
        pf("Case %d:\n", i);
        curr = "http://www.lightoj.com/";
        stack <string> ff;
        stack <string> bb;
        while(cin >> comm)
        {
            if(comm == "QUIT")
                break;
            else if(comm == "VISIT")
            {
                bb.push(curr);
                cin >> curr;
                pf("%s\n", curr.c_str());
                while(!ff.empty())
                    ff.pop();
            }
            else if(comm == "BACK")
            {
                if(!bb.empty())
                {
                    ff.push(curr);
                    curr = bb.top();
                    bb.pop();
                    pf("%s\n", curr.c_str());
                }
                else
                    pf("Ignored\n");

            }
            else if(comm == "FORWARD")
            {
                if(!ff.empty())
                {
                    bb.push(curr);
                    curr = ff.top();
                    ff.pop();
                    pf("%s\n", curr.c_str());
                }
                else
                    pf("Ignored\n");
            }
        }
    }

    return 0;
}
