#include <bits/stdc++.h>
#define pf printf
#define sf scanf
using namespace std;

struct pair_pair
{
    int num;
    int xcor;
    int ycor;
};

typedef long long int ll;
typedef struct pair_pair pp;
char str[55][55];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int visit[55][55], n, m, k;
bool ocean = false;
//pp mm[2500];

bool comp(pp x, pp y)
{
    if(x.num > y.num)
        return true;
    return false;
}

int lake_finder(int x, int y)
{
    if(x == 0 || x == n-1 || y == 0 || y == m-1)
    {
        ocean = true;
        return 0;
    }

    int i, cnt = 1;
    visit[x][y] = 1;
    for(i = 0; i < 4; i++)
    {
        if(str[x+dx[i]][y+dy[i]] == '.' && visit[x+dx[i]][y+dy[i]] == 0)
            cnt += lake_finder(x+dx[i], y+dy[i]);
    }
    return cnt;
}

void floodFill(int x, int y)
{
    if(x == 0 || x == n-1 || y == 0 || y == m-1)
        return ;
    str[x][y] = '*';
    for(int i = 0; i < 4; i++)
        if(str[x+dx[i]][y+dy[i]] == '.')
            floodFill(x+dx[i], y+dy[i]);
}

int main()
{
    int i, j, cnt, mini;
    sf("%d %d %d", &n, &m, &k);
    for(i = 0; i < n; i++)
        scanf("%s", str[i]);
    vector < pp > mm;
    pp temp;
    for(i = 1; i < n-1; i++)
        for(j = 1; j < m-1; j++)
            if(str[i][j] == '.' && visit[i][j] == 0)
            {
                ocean = false;
                cnt = lake_finder(i, j);
                if(ocean == false)
                    {
                        temp.num = cnt;
                        temp.xcor = i;
                        temp.ycor = j;
                        mm.push_back(temp);
                    }
            }
    mini = 0;
    sort(mm.begin(), mm.end(), comp);
    if(mm.size() > k)
    {
        vector< pp >::iterator mi;
        int qq = 0;
        for(mi = mm.begin(); mi != mm.end(); mi++)
        {
            if(qq >= k)
            {
                floodFill((*mi).xcor, (*mi).ycor);
                mini += (*mi).num;
            }
            qq++;
        }
    }
    printf("%d\n", mini);
    for(i = 0; i< n; i++)
        printf("%s\n", str[i]);

    return 0;
}
