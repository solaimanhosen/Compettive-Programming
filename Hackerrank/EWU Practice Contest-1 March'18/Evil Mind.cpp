#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX           2000009

int myList[100000010];

int main()
{
    int t, n, num, cnt;
    scanf("%d", &t);

    for(int i = 1; i <= t; i++){
        scanf("%d", &n);
        cnt = 0;
        for(int j = 1; j <= n; j++){
            scanf("%d", &num);
            if(myList[num] != i+1){
                myList[num] = i + 1;
                cnt++;
            }
        }
        printf("Case %d: %d\n", i, cnt);
    }




    return 0;
}
