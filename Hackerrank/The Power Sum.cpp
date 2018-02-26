#include<iostream>
#include<cstdio>

using namespace std;

int solution;

int pow(int base, int term)
{
    int res = 1;
    for(int i = 1; i <= term; i++){
        res *= base;
    }
    return res;
}

void solve(int curSum, int curNum, int tar, int term)
{
    if(curSum == tar){
        solution++;
        return;
    }
    for(int i = curNum + 1; curSum + pow(i,term) <= tar; i++){
        solve(curSum+pow(i,term),i,tar,term);
    }
}

int main()
{
    int x, n, base;

    scanf("%d", &x);
    scanf("%d", &n);

    solution = 0;
    solve(0,0,x,n);

    printf("%d\n", solution);


    return 0;
}





