#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long male, female, total, queen = 1, temp1, temp2;
    int year;
    while(scanf("%d", &year) == 1 && year != -1){
        total = male = female = 0;
        for(int i = 0; i < year; i++){
            temp1 = female;
            temp1 += male;
            temp2 = male;
            male = temp1 + 1;
            female = temp2;
        }
        total = male + female +1;
        printf("%lld %lld\n", male, total);
    }


    return 0;
}
