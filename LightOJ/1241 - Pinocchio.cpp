#include<bits/stdc++.h>
#define sfi(n) scanf("%d", &n)
#define sfl(n) scanf("%lld", &n)
#define sfd(n) scanf("%lf", &n)
#define sfi2(x, y) scanf("%d %d", &x, &y);
#define sfl2(x, y) scanf("%lld %lld", &x, &y);
#define sfd2(x, y) scanf("%lf %lf", &x, &y);
#define pf(n) printf("%d", n)
#define pfc(i) printf("Case %d: ", i)
#define pfn(n) printf("%d\n", n)
#define pfdn(n) printf("%f\n", n)
#define pb push_back
#define bl printf("\n")
#define spc putchar(' ')
#define fli() freopen("in.txt","r",stdin)
#define flo() freopen("out.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define f   first
#define s   second
#define PI acos(-1)
#define debug(x) cerr << #x << " : " << x << endl
#define find puts("I am here")
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define MOD 1000000007
#define EPS 1e-7
#pragma comment(linker, "/stack:20000000")
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000005
#define N   100

using namespace std;


int main()
{
    //fli();
    //flo();
    int t, n, ans, caseNo=1, preLen, Len, newLen;
    sfi(t);
    while(t--)
    {
        ans = 0;
        preLen = 2;
        sfi(n);
        for(int i = 1; i <= n;i++)
        {
            sfi(newLen);
            if(newLen > preLen){
                Len = newLen - preLen;
                preLen = newLen;
                ans+=Len/5;
                if(Len%5!=0)
                    ans++;
            }
        }
        printf("Case %d: %d\n",caseNo++,ans);
    }

    return 0;
}
