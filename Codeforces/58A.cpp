#include <bits/stdc++.h>
#define sf scanf
#define pf printf
#define si(x) scanf("%d", &x)
#define pff(x) printf("%d\n", x)
#define pb push_back
#define N 31622800

using namespace std;

typedef long long int ll;

int main()
{
    string word, hello = "hello";
    int i, j;
    while( cin >> word)
    {
        j = 0;
        for(i = 0; i < word.length(); i++)
            if(word[i] == hello[j])
            {
                j++;
                if(j == 5)
                    break;
            }
        if(j == 5)
            cout << "YES\n";
        else
            cout <<"NO\n";
    }

    return 0;
}


