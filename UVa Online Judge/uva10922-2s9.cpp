#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    int sum, degree, num, i;
    while(cin>>line && !(line.length()== 1 && line[0] == '0')){
        sum = 0;
        for(i = 0; i < line.length(); i++){
            sum += line[i] - '0';
        }
        if(sum % 9 != 0)
            cout<<line<<" is not a multiple of 9."<<endl;
        else{
            degree = 1;
            while(sum>9){
                num = 0;
                while(sum != 0){
                    num += sum%10;
                    sum/=10;
                }
                sum = num;
                degree++;
            }
            cout<<line<<" is a multiple of 9 and has 9-degree "<<degree<<"."<<endl;
        }
    }
    return 0;
}
