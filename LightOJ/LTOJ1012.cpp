using namespace std;

#include <bits/stdc++.h>
#define sf              scanf
#define si(x)           scanf("%d", &x)
#define sl(x)           scanf("%lld", &x)
#define ss(x)           sf("%s", x)
#define pf              printf
#define pfc(x)          pf("Case %d: ", x)
#define pfv(x)          pf("%d\n", x)
#define pb              push_back
#define N               105
#define PI              3.40954185
#define F               first
#define S               second

struct point
{
    int xcor;
    int ycor;
};

char grid[N][N];
bool visit[N][N];
int m,n;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool valid(point p)
{
    if(p.xcor >= 0 && p.xcor < m && p.ycor >= 0 && p.ycor < n)
        return true;
    return false;
}

void bfs(point src, int &cnt)
{
    //puts("Inside Bfs");
    point p;
    cnt++;
    visit[src.xcor][src.ycor] = true;
    queue<point> q;
    q.push(src);
    //cout << n << " " << m << endl;
    while(!q.empty()){
        src = q.front();
        //cout << src.xcor << "  " << src.ycor << endl;
        q.pop();
        for(int i = 0; i < 4; i++){
            p.xcor = src.xcor + dx[i];
            p.ycor = src.ycor + dy[i];
            //cout << p.xcor << "  " << p.ycor <<" "<< valid(p) << endl;
            if(!visit[p.xcor][p.ycor] && grid[p.xcor][p.ycor] == '.' && valid(p)){
                q.push(p);
                visit[p.xcor][p.ycor] = true;
                cnt++;
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t, caseNo = 1, i, j, cnt;
    point p;


    si(t);
    while(t--)
    {
        cnt = 0;
        memset(visit, 0, sizeof(visit));
        si(n);
        si(m);

        for(i = 0; i < m; i++)
            ss(grid[i]);

        /*cout << "Test case : " << t << "  W : " << n << "  H : " << m << endl;
        for(i = 0; i < m; i++)
            cout << grid[i] << endl;
        cout << endl;*/

        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(grid[i][j] == '@'){
                    //puts("Home found");
                    p.xcor = i;
                    p.ycor = j;
                    bfs(p, cnt);
                }
            }
        }
        pfc(caseNo++);
        pfv(cnt);
    }

    return 0;
}



