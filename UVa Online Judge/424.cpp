#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
   long long  int value;
   long long int result =0;
    while(value>=0){
        cin >> value;
        if(value==0)
            break;
            else {
                result+=value;
            }
    }
    cout<< result <<endl;
    return 0;
}
