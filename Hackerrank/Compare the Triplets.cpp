#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a0,a1,a2,sum1,b0,b1,b2,sum2;
    cin >> a0 >> a1 >> a2;
    cin >> b0 >> b1 >> b2;
    sum1 = sum2 = 0;

    if(a0 > b0)
        sum1++;
    if(a0 < b0)
        sum2++;

    if(a1 > b1)
        sum1++;
    if(a1 < b1)
        sum2++;
    if(a2 > b2)
        sum1++;
    if(a2 < b2)
        sum2++;

    cout << sum1 << " " << sum2 << endl;
}

