#include <iostream>
#include <cstring>
#define INT_MAX         (1<<31)-1
 
using namespace std;
 
int n, k;
 
long long dp[35][35*35];
bool visit[35][35];
 
void init()
{
    memset(dp, -1, sizeof(dp));
    memset(visit, false, sizeof(visit));
}
 
bool isSafe(int row, int col)
{
    for (int i = 1; i < row; i++){
        if (visit[i][col])
            return false;
    }
    return true;
}
 
long long solve(int row, int taken)
{
    if (taken == k){
        return 1;
    }
    if (row > n){
        return 0;
    }
   
       
    if (dp[row][taken] != -1){
        return dp[row][taken];
    }
    long long ways = 0;
    ways = solve(row + 1, taken);
    for (int i = 1; i <= n; i++){
        if (isSafe(row, i)){
            visit[row][i] = true;
            ways += solve(row + 1, taken + 1);
            visit[row][i] = false;
        }
       
    }
    dp[row][taken] = ways;
    return dp[row][taken];
}
 
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; testCase++){
        cin >> n >> k;
        init();
        cout <<"Case " << testCase <<": " << solve(1, 0) << endl;
    }
   
    return 0;
}