#include <bits/stdc++.h>

using namespace std;

int main()
{
    string num;
    int i,j, rem, temp;
    while(cin>>num && !(num.length() == 1 && num[0] == '0')){
        rem = 0;
        i = 0;
        while(num[i] != NULL){
            temp = rem*10 + (num[i++] - '0');
            rem = temp%11;
        }
        if(rem == 0)
            cout<<num<<" is a multiple of 11."<<endl;
            //printf("%s is a multiple of 11.\n",num);
        else
            //printf("%s is not a multiple of 11.\n",num);
            cout<<num<<" is not a multiple of 11."<<endl;
    }
    return 0;
}
