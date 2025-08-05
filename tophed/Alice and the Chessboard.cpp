#include <bits/stdc++.h>

using namespace std;

int main()
{
    short int t, a, b, c, d;
    cin >> t;
    while(t--)
    {
        //cout << t << endl;
        //scanf("%d %d %d %d", &a, &b, &c, &d);
        cin >> a >> b >> c >> d;
        if(a >= c)
            a = a-c;
        else
            a = c-a;
        if(b >= d)
            b = b-d;
        else
            b = d-b;
        if(a != b)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
