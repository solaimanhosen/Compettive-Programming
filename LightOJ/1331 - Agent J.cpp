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


void myself()
{
    //fli();
    //flo();
    int t, caseNo = 1;
    double r1, r2, r3, a, b, c, A, B, C, area, s;

    sfi(t);
    while(t--)
    {
        scanf("%lf %lf %lf",&r1,&r2,&r3);

        a = r1 + r2;
        b = r2 + r3;
        c = r1 + r3;

        A = acos((b*b+c*c-a*a)/(2*b*c));
        B = acos((a*a+c*c-b*b)/(2*a*c));
        C = acos((a*a+b*b-c*c)/(2*a*b));

        s = (a+b+c)/2;

        area = sqrt(s*(s-a)*(s-b)*(s-c));

        area -= 0.5*(r3*r3*A + r1*r1*B + r2*r2*C);

        printf("Case %d: %.6lf\n", caseNo++, area);
    }

}

int main() {
    myself();
    return 0;
}

