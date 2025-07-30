#include <bits/stdc++.h>

using namespace std;

string remFirstZero(string num)
{
    int i;
    bool positive = false;
    string temp = "";
    for(i = 0; i < num.length(); i++){
        if(num[i] != '0'){
            positive = true;
            temp+= num[i];
        }
        else if(num[i] == '0' && positive == true)
            temp += '0';
    }
    if(positive == false)
            temp+= '0';
    return temp;
}

string addRev(string num1, string num2)
{
    int i,sum, t=0;
    string temp;
    if(num1.length()<num2.length()){
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    temp = "";
    for(i = 0; i < num1.length(); i++){
        if(i < num2.length())
            sum = (num1[i] - '0') + (num2[i] - '0')+t;
        else
            sum = (num1[i] - '0') + t;
        t = 0;
        if(sum >= 10){
            sum%=10;
            t = 1;
        }
        temp+= (sum+'0');
        if(i == num1.length()-1 && t == 1)
            temp+='1';
    }
    return remFirstZero(temp);
}

int main()
{
    int t;
    string num1, num2;
    cin>>t;
    while(t--){
        cin>>num1>>num2;
        cout<<addRev(num1,num2)<<endl;
    }
    return 0;
}
