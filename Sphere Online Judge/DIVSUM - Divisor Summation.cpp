#include <bits/stdc++.h>

using namespace std;

map <int, int> divSum;

void findDivisor()
{
    int i ,j;
    for(i = 1; i <= 500000; i++){
        for(j = i; j <= 500000; j += i){
            divSum[j] += i;
        }
    }
    for(i = 1; i <= 500000; i++) divSum[i] -= i;
    //puts("done");
}

int main()
{
    findDivisor();

    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", divSum[n]);
    }



    return 0;
}
