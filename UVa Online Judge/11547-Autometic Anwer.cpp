#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int testcase;
    cin >> testcase;
    for(int i=0;i<testcase ;i++){
        int n;
        cin>> n;
        int result;
        int r;
        result =(((((n*567)/9)+7492)*235/47)-498);
        if(result <0){
            r =result*(-1);
        }
        else {
                r=result;
    }
    int  temp=r;
    int div;
    for(int j=0;j<2;j++){
        div=temp%10;
        temp=temp/10;
    }
    cout<< div << endl;
    }
    return 0;


}
