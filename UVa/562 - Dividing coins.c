#include <stdio.h>

#define SIZE_M 101
#define SIZE_SUM 50001

int binary[SIZE_M];
int m, coin[SIZE_M];
int Total;
int Ans;
int DP[SIZE_M][SIZE_SUM];

void initDP()
{
    int i, j;
    for(i = 0; i < SIZE_M; i++){
        for(j = 0; j < SIZE_SUM; j++){
            DP[i][j] = -1;
        }
    }
}

int abs(int n)
{
    if(n < 0)
        return -n;
    return n;
}

int solve(int i, int sum1)
{
    int left, right;
    int sum2;
    if(DP[i][sum1] >= 0)
        return DP[i][sum1];
    if(i == m){
        sum2 = Total - sum1;
        return DP[i][sum1] = abs(sum1 - sum2);
    }
    binary[i] = 0;
    left = solve(i+1, sum1);
    binary[i] = 1;
    right = solve(i+1, sum1+coin[i]);
    if(left < right)
        return DP[i][sum1] = left;
    else
        return DP[i][sum1] = right;
}

void readCase()
{
    int i ;
    scanf("%d", &m);
    for(i = 0; i < m; i++)
        scanf("%d", &coin[i]);
}

void solveCase()
{
    int i;
    Total = 0;
    for(i = 0; i < m; i++)
        Total += coin[i];
    initDP();
    Ans = solve(0, 0);
}

void printCase()
{
    printf("%d\n", Ans);
}

int main2()
{
    int n;
    scanf("%d", &n);
    while(n--){
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}
