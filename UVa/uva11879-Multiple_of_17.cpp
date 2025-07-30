#include <bits/stdc++.h>

using namespace std;

int main()
{
    string num;
    while(cin>>num && !(num.length() && num[0] == '0')){
        int rem = 0, n;
        for(int i = 0; i<num.length(); i++){
            n = rem*10 + num[i] - '0';
            rem = n%17;
        }
        if(rem == 0)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0;
}
