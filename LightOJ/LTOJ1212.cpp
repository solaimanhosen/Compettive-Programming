
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
    int t, n, m, caseNo = 1, num;
    string comm;
    si(t);
    while(t--)
    {
        deque <int> q;
        pf("Case %d:\n", caseNo++);
        si(n);
        si(m);
        for(int i = 1; i <= m; i++)
        {
            //scanf("%s", comm.c_str());
            cin >> comm;
            if(comm == "pushLeft")
            {
                si(num);
                if(q.size() == n) pf("The queue is full\n");
                else
                {
                    q.push_front(num);
                    pf("Pushed in left: %d\n", num);
                }
            }
            else if(comm == "pushRight")
            {
                si(num);
                if(q.size() == n) pf("The queue is full\n");
                else
                {
                    q.push_back(num);
                    pf("Pushed in right: %d\n", num);
                }
            }
            else if(comm == "popLeft")
            {
                if(q.empty()) pf("The queue is empty\n");
                else
                {
                    pf("Popped from left: %d\n", q.front());
                    q.pop_front();
                }
            }
            else
            {
                if(q.empty()) pf("The queue is empty\n");
                else
                {
                    pf("Popped from right: %d\n", q.back());
                    q.pop_back();
                }
            }
        }
    }
    return 0;
}
