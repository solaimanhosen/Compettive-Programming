#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 165000

using namespace std;

typedef long long int ll;

vector <int> prime;
bool mark[N+2];

void seive()
{
    int i, j;
    prime.pb(1);
    prime.pb(2);
    for(i = 3; i*i < N; i+=2)
        if(!mark[i])
            for(j = i+i; j <N; j += i)
                mark[j] = true;
    for(i = 3; i<N; i+=2)
        if(!mark[i])
            prime.pb(i);
}

int main()
{
    seive();
    int n, t;
    si(t);
    while(t--)
    {
        si(n);
        pff(prime[n]);
    }
    return 0;
}
