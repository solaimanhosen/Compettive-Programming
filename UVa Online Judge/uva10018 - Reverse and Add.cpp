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

ll rev(ll n)
{
    ll result = 0;
    while(n)
    {
        result = result*10+n%10;
        n/=10;
    }
    return result;
}

bool isPalindrome(ll n)
{
    if(n == rev(n))
        return true;
    return false;
}


int main()
{
    //fli();
    //flo();
    ll t, n;
    sfl(t);
    while(t--){
        sfl(n);
        int cnt = 0;
        while(true)
        {
            cnt++;
            n += rev(n);
            if(isPalindrome(n))
                break;
        }
        printf("%d %lld\n",cnt,n);
    }


    return 0;
}
