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

bool isPalindrome(ll n)
{
    int res = 0;
    int nn = n;
    while(nn>0)
    {
        res = res*10+nn%10;
        nn/=10;
    }
    if(n==res)
        return true;
    return false;
}


int main()
{
    //fli();
    ll t, n, caseNo = 1;
    sfl(t);
    while(t--){
        sfl(n);
        if(isPalindrome(n))
            printf("Case %d: Yes\n", caseNo++);
        else
            printf("Case %d: No\n", caseNo++);
    }

    return 0;
}
