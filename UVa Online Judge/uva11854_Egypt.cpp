#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num[3], i, j, temp;
    while(cin>>num[0]>>num[1]>>num[2] && (num[0] != 0 || num[1] != 0 || num[2] != 0)){
        for(i = 1; i <= 2; i++)
            for(j = 0; j < 2; j++)
                if(num[j]>num[j+1]){
                    temp = num[j];
                    num[j] = num[j+1];
                    num[j+1] = temp;
                }
        if(num[2]*num[2] == (num[1]*num[1] + num[0]*num[0]))
            cout<<"right"<<endl;
        else
            cout<<"wrong"<<endl;
    }
    return 0;
}
