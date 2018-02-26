/*----------------------------------------------------------------*/
/*       ____                                                     */
/*      /----\                                                    */
/*      ||                                                        */
/*      ||___   _          _        ____          ____   _        */
/*      \----\  \|        |/ /\    /  _ \  |\ || |_.._| |.|       */
/*           ||  \\  /\  // //\\   | |_| | | \||   ||   |.|       */
/*       ____||   \\//\\// //--\\  | ___/  ||\ |  _||_  |.|____   */
/*      \----/     \/  \/ |/    \| ||      || \| |____| \______|  */
/*                                                                */
/*                                                                */
/*      UVa        : swapnilsaha.me                               */
/*      Codeforces : swapnilsaha                                  */
/*      Lightoj    : Swapnil Saha                                 */
/*      Spoj       : swapnilsaha                                  */
/*                                    ____________________________*/
/*                                   | From,                      */
/*                                   |      Bangladesh. <3 <3     */
/*----------------------------------------------------------------*/


#include<bits/stdc++.h>
using namespace std;

#define ll          long long int
#define sf          scanf
#define pf          printf
#define F           first
#define S           second
#define pb          push_back
#define GCD(a, b)   __gcd(a, b)
#define LCM(a, b)   ((a*b)/GCD(a, b))

#define MOD         1000000007
#define M           10000

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

vector<string>g;
int vis[60][60], n, m, k;

int x[]={0, 0, 1, -1};
int y[]={1, -1, 0, 0};


struct st
{
    int i, j, len, ser;
};

bool comp(st a, st b)
{
    return a.len<b.len;
}

int BFS(int a, int b, int ser)
{
    bool prove=true;

    if(a==0 || a==n-1 || b==0 || b==m-1)
    {
        prove=false;
    }

    st temp, one;

    queue<st>Q;
    temp.i=a;
    temp.j=b;
    Q.push(temp);
    vis[a][b]=ser;

    int cnt=1;
    while(!Q.empty())
    {
        temp=Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            one.i=temp.i+x[i];
            one.j=temp.j+y[i];

            if(0<=one.i && one.i<n && 0<=one.j && one.j<m)
            {
                a=one.i;
                b=one.j;
                if(!vis[one.i][one.j] && g[one.i][one.j]=='.')
                {
                    vis[one.i][one.j]=ser;
                    Q.push(one);
                    if(one.i==0 || one.i==n-1 || one.j==0 || one.j==m-1)
                    {
                        prove=false;
                    }
                    if(prove)
                    {
                        cnt++;
                    }
                }
            }
        }
    }
    if(prove)
    {
        return cnt;
    }
    else
    {
        return MOD;
    }
}

int col(int c)
{
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vis[i][j]==c)
            {
                g[i][j]='*';
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    string abcd;

    cin >> n >> m >> k;

    for(int i=0; i<n; i++)
    {
        cin >> abcd;
        g.pb(abcd);
    }

    int cnt=1;
    st temp;
    vector<st>vv;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!vis[i][j] && g[i][j]=='.')
            {
                temp.i=i;
                temp.j=j;
                temp.len=BFS(i, j, cnt);
                temp.ser=cnt;
                cnt++;
                if(temp.len<MOD)
                {
                    vv.pb(temp);
                }
            }
        }
    }

    sort(vv.begin(), vv.end(), comp);

    cnt=0;
    queue<st>Q;
    for(int i=0; i<vv.size(); i++)
    {
        Q.push(vv[i]);
        //cout << vv[i].i << " " << vv[i].j << " " << vv[i].ser << " " << vv[i].len << endl;
    }

    cnt=0;
    while(Q.size()>k && Q.size())
    {
        temp=Q.front();
        Q.pop();
        cnt+=col(temp.ser);
    }

    cout << cnt << endl;
    for(int i=0; i<n; i++)
    {
        cout << g[i] << endl;
    }

    return 0;
}
