#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

#define MAX 1000009
#define ll  long long

double sqrt(double num)
{
    if(num >= 0){
        double x = num;
        int i;
        for(i = 0; i < 20; i ++){
            x = (x + (num/x))/2;
        }
        return x;
    }
    return 0;
}

void solve(int ans[MAX])
{
    for(int i = 0; i < MAX; i++)
        ans[i] = i;

    int sqrtMax = (int)sqrt((double)MAX);

    for(int i = 2; i < MAX; i++){
        if(ans[i] > ans[i-1]+1){
            ans[i] = ans[i-1] + 1;
        }

        int limit;
        if(i <= sqrtMax){
            limit = i*i;
        }else{
            limit = MAX;
        }

        for(int j = i+i; j <= limit; j+=i){
            if(ans[j] > ans[i]+1){
                ans[j] = ans[i]+1;
            }
        }
    }
}

int main()
{
    int ans[MAX];
    int n, q;

    solve(ans);

    scanf("%d", &q);
    while(q--){
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }

    return 0;
}
