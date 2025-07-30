#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,num[7],total,i,j,temp,Case = 1;
    char grade;
    cin>>t;
    while(t--){
        total = 0;
        for(i = 0; i < 7; i++)
            cin>>num[i];
        for(i = 1; i <= 2; i++){
            for(j = 4; j < 6; j++){
                if(num[j]<num[j+1]){
                    temp = num[j];
                    num[j] = num[j+1];
                    num[j+1] = temp;
                }
            }
        }
        num[4] = (num[4] + num[5])/2;
        for( i = 0; i < 5; i++)
            total += num[i];
        if(total >= 90)
            grade = 'A';
        else if(total >= 80)
            grade = 'B';
        else if(total >= 70)
            grade = 'C';
        else if(total >= 60)
            grade = 'D';
        else
            grade = 'F';

        cout<<"Case "<<Case++<<": "<<grade<<endl;

    }
    return 0;
}
