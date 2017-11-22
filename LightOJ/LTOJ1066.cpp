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

class Point
{
public:
    int x;
    int y;
};

Point letters[30];
char grid[20][20];
bool visit[20][20];
int dist[20][20];
int n;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int BFS(Point cor, int next)
{
    visit[cor.x][cor.y] = true;
    dist[cor.x][cor.y] = 0;
    Point src, temp;
    queue <Point> q;
    q.push(cor);
    //cout << "Source : \n";
    while(!q.empty())
    {
        src = q.front();
        //pf("%d %d\n", src.x, src.y);
        q.pop();
        for(int i = 0; i < 4; i++){
            temp.x = src.x + dx[i];
            temp.y = src.y + dy[i];
            //cout << "child : " << endl;
            if(temp.x >= 1 && temp.x <= n && temp.y >= 1 && temp.y <= n && visit[temp.x][temp.y] == false && grid[temp.x][temp.y] != '#' && !(grid[temp.x][temp.y] != 'A' + next && grid[temp.x][temp.y] >='A' && grid[temp.x][temp.y] <='Z')){
                visit[temp.x][temp.y] = true;
                dist[temp.x][temp.y] = dist[src.x][src.y] + 1;
                q.push(temp);

                //cout << grid[temp.x][temp.y] << " "<< 'A' + next << endl;

                if(grid[temp.x][temp.y] == 'A' + next)
                {
                   // cout << "match : " << endl;
                    grid[cor.x][cor.y] = '.';
                    return dist[temp.x][temp.y];
                }

            }
        }

    }
    return 0;
}


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, caseNo = 1, minMove, letter_count;
    bool check;

    Point cor;

    si(t);
    while(t--)
    {
        minMove = 0;
        letter_count = 0;
        check = false;

        memset(dist, 0, sizeof(dist));
        si(n);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> grid[i][j];
                if(grid[i][j] >= 'A' && grid[i][j] <= 'Z')
                {
                    cor.x = i;
                    cor.y = j;
                    letters[grid[i][j]-65] = cor;
                    letter_count++;
                }
            }
        }



        for(int i = 1; i < letter_count && check == false; i++){
            memset(visit, false, sizeof(visit));
            int num = BFS(letters[i-1], i);

            //cout << "Return Value : " << num << endl;
            if(num == 0){
                check = true;
            }
            minMove += num;
        }
        if(check == false)
            pf("Case %d: %d\n", caseNo++, minMove);
        else
            pf("Case %d: Impossible\n", caseNo++);
    }



    return 0;
}

