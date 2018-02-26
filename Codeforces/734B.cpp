
#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 165000

using namespace std;

typedef long long int ll;

int main()
{
    int a, b, c, d, k;
    while(cin >> a>> b>> c>> d)
    {
        k = min(min(a,c), d);
        ll sum = 256*k + min(a-k, b)*32;
        cout << sum << endl;
    }

    return 0;
}
