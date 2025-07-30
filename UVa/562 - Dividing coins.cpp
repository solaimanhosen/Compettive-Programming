#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX     101
#define S_MAX   50001

int coins[MAX];
int taken[MAX];
int dp[MAX][S_MAX];
int visited[MAX][S_MAX];
int m, total;


int abs(int num)
{
    if(num < 0)
        return -num;
    return num;
}

int mini(int n1, int n2)
{
	if (n1 <= n2)
		return n1;
	return n2;
}

int solve(int i, int sum)
{
    if(visited[i][sum]){
        return dp[i][sum];
    }
    int Left, Right;
    if(i == m){
        visited[i][sum] = true;
        int sum2 = total - sum;
        dp[i][sum] = abs(sum-sum2);
        return dp[i][sum];
    }
    taken[i] = 0;
    Left = solve(i+1,sum);
    taken[i] = 1;
    Right = solve(i+1, sum + coins[i]);
	visited[i][sum] = true;
    return dp[i][sum] = mini(Left, Right);
}


void reset()
{
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < S_MAX; j++){
            visited[i][j] = false;
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        total = 0;
        reset();
        for(int i = 0 ; i < m; i++){
            scanf("%d", &coins[i]);
            total += coins[i];
        }

		printf("%d\n", solve(0, 0));
    }


    return 0;
}
