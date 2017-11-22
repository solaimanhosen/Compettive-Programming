#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m, t;
    scanf("%lld", &t);

    for(int i = 1; i <= t; i++){
        scanf("%lld%lld", &n, &m);
        printf("Case %d: %lld\n", i, m * (n/2));
    }

    return 0;
}
