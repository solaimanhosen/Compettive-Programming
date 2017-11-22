#include <bits/stdc++.h>

using namespace std;

#define pf printf

int divNum[1001], num[1000];

void divFinder()
{
    int i, j;
    for(i = 1; i <= 1000; i++){
        num[i - 1] = i;
        for(j = i; j <= 1000; j += i)
            divNum[j]++;
    }
}

bool comp(int i, int j)
{
    if(divNum[i] < divNum[j])
        return true;
    else if(divNum[i] == divNum[j])
        return i > j;
    return false;
}

int main()
{
    int i, n, t, cc = 1;
    divFinder();
    sort(num, num + 1000, comp);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        pf("Case %d: %d\n", cc++, num[n - 1]);
    }

    return 0;
}
