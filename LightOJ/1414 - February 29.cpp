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


int main() {
    //fli();
    //flo();

    int t, startingYear, endingYear, startingDate, endingDate, caseNo = 1, leapYear = 0;
    char startingMonth[20], endingMonth[20];

    sfi(t);
    while(t--)
    {
        leapYear = 0;
        scanf("%s %d, %d",startingMonth, &startingDate, &startingYear);
        scanf("%s %d, %d",endingMonth, &endingDate, &endingYear);

        if(strcmp(startingMonth,"January")!=0 && strcmp(startingMonth,"February")!=0)
            startingYear++;
        if(strcmp(endingMonth,"January")==0 || (strcmp(endingMonth,"February")==0 && endingDate < 29))
            endingYear--;



        leapYear += endingYear/4 - (startingYear - 1)/4;
        leapYear -= endingYear/100 - (startingYear - 1)/100;
        leapYear += endingYear/400 - (startingYear - 1)/400;

        printf("Case %d: %d\n", caseNo++, leapYear);
    }
    return 0;
}


