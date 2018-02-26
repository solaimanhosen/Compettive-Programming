#include <bits/stdc++.h>

using namespace std;

int mat[4000][4000];

int main()
{
    int n, sum1, sum2, diff, i, j;

    cin >> n;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    i = j = sum1 = sum2 = 0;
    while(i < n){
        sum1 += mat[i++][j++];
    }

    i = 0;
    j = n - 1;
    while(j >= 0){
        sum2 += mat[i++][j--];
    }

    if(sum1 > sum2)
        cout << sum1 - sum2 << endl;
    else
        cout << sum2 - sum1 << endl;



}



