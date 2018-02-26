
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
    int n, an, dn;
    string str;
    while(cin >> n)
    {
        cin >> str;
        an = dn = 0;
        for(int i = 0; i < str.length(); i++)
        {
           if(str[i] == 'A') an++;
            else dn++;
        }
        if(an > dn)
            puts("Anton");
        else if(dn > an)
            puts("Danik");
        else
            puts("Friendship");
    }

    return 0;
}
