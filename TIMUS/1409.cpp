
#include <bits/stdc++.h>
#define si(x)           scanf("%d",&x)
#define sii(x, y)       scanf("%d %d", &x, &y)
#define siii(x, y, z)   scanf("%d %d %d", &x, &y, &z)
#define sll(x)          scanf("%lld", &x)
#define pc(x)           printf("Case %lld:", x)
#define pcv(x)          printf(" %d", x)
#define pv(x)           printf("%d", x)
#define pn()            printf("\n")
#define pf              printf
#define sf              scanf
#define N               100000

typedef long long int ll;

using namespace std;

int main()
{
    int a, b, total;
    sii(a, b);
    total = a + b -1;
    pf("%d %d", total-a, total-b);
    pn();

    return 0;
}


