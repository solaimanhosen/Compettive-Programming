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
#define pii             pair<int,int>
#define mp              make_pair

using namespace std;

int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};
char board[10][10];
bool visit[10][10];

bool valid(int x, int y)
{
     if(x >= 0 && x < 8 && y >= 0 && y < 8)
        return true;
     return false;
}


int main()
{

    int testCase, kx, ky, px, py, ways;
    bool pfound, bfound, rfound, nfound, kfound, qfound;
    pii b, r, n, k, q;

    sfi(testCase);
    getchar();
    while(testCase--)
    {
        ways = 0;
        pfound = rfound = nfound = kfound = bfound = false;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                scanf("%c", &board[i][j]);
                if(board[i][j] == 'k'){
                    k.f = i;
                    k.s = j;
                    kfound = true;
                }

                if(board[i][j] == 'B'){
                    b.f = i;
                    b.s = j;
                    bfound = true;
                }
                if(board[i][j] == 'R'){
                    r.f = i;
                    r.s = j;
                    rfound = true;
                }
                if(board[i][j] == 'N'){
                    n.f = i;
                    n.s = j;
                    nfound = true;
                }
                if(board[i][j] == 'Q'){
                    q.f = i;
                    q.s = j;
                }
                if(board[i][j] == 'P' && board[i-1][j] == '#'){
                    px = i-1;
                    py = j;
                }
            }
            getchar();
        }
        //px--;
        /*for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'P'){
                    pfound = true;
                    if(bfound && abs(b.f - i-1) == abs(b.s - j)){
                        pfound == false;
                    }
                    if(rfound && (r.f == i-1 || r.s == j)){
                        pfound = false;
                    }
                    if(nfound){
                        for(int k = 0; k < 8; k++){
                                int x = dx[k] + i-1;
                                int y = dy[k] + j;
                                if(valid(x,y)){
                                    if(x == i-1 && y == j)
                                        pfound = false;
                                }
                            }
                    }
                    if(kfound && abs(k.f-i-1) <= 0 && abs(k.s-j) <= 0)
                        pfound = false;
                    if(pfound)
                    {
                        px = i-1;
                        py = j;
                    }
                }
            }
        }*/

        //cout << px << " pawn " << py << endl;
        //cout << k.f << " king" << k.s << endl;



        nfound = false;
        if(abs(k.f-px) == abs(k.s-py))
            ways += 2;
        if(k.f == px || k.s == py)
            ways += 2;

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                int x = dx[i] + px;
                int y = dy[i] + py;
                if(valid(x,y) && x == k.f && y == k.s && nfound == false)
                {
                    ways++;
                    nfound = true;
                }

            }
        }

        pf("%d\n",ways);
    }

    return 0;
}



