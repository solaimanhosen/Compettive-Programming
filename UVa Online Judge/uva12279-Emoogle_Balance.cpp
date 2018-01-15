#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,num,balance,Case = 1;
    while(cin>> t && t != 0){
        balance = 0;
        for(int i = 1; i <= t; i++){
            cin>>num;
            if(num == 0)
                balance--;
            else
                balance++;
        }
        cout<<"Case "<<Case++<<": "<<balance<<endl;
    }
    return 0;
}
