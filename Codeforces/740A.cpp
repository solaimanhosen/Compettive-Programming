#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pfi(x) printf("%d\n", x)
#define pb push_back
#define N 165000

using namespace std;

typedef long long int ll;

int main()
{
    ll n, a, b, c, rem;
    while(cin >> n >> a >> b >> c)
    {
        rem = n % 4;
        if(rem == 0)
            cout << "0" << endl;
        if(rem == 1)
            cout << min(min(a*3,c),a+b) << endl;
        if(rem == 2)
            cout << min(min(b,2*a),2*c) << endl;
        if(rem == 3)
            cout << min(min(a,b+c),3*c) << endl;
    }
    return 0;
}
