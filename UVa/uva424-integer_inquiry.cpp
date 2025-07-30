#include <bits/stdc++.h>

using namespace std;

string rev(string num)
{
    string temp = "";
    for(int i = num.length()-1; i>=0; i--){
        temp+= num[i];
    }
    return temp;
}

string add(string num1, string num2)
{
    string temp;
    int i, j, sum = 0, rem = 0;
    if(num1.length()<num2.length()){
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    temp = "";
    for(i = 0; i< num1.length(); i++){
        if(i<num2.length()){
            sum = rem + (num1[i] - '0') + (num2[i] - '0');
            rem = 0;
            if(sum>9){
                sum%=10;
                rem = 1;
            }
            temp+= (sum + '0');
            if(i == num1.length()-1 && rem == 1)
                temp+= '1';
        }
        else{
            sum = rem + (num1[i] - '0');
            rem = 0;
            if(sum>9){
                sum%=10;
                rem = 1;
            }
            temp+= (sum + '0');
            if(i == num1.length()-1 && rem == 1)
                temp+= '1';
        }
    }
    return temp;
}

int main()
{
    string sum, num;
    while(cin>>num && num != "0"){
        num = rev(num);
        sum = add(num,sum);
    }
    cout<<rev(sum)<<endl;
    return 0;
}
