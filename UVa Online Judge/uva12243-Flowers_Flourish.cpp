#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    while(getline(cin,str) && str[0]!='*'){
        int i = 1, sign = 1;
        char ch = tolower(str[0]);
        while(str[i]!='\0' && sign == 1){
            if(str[i]==' ' && (tolower(str[i+1]) != ch))
                sign=0;
            i++;
        }
    if(sign == 1)
        cout<<"Y"<<endl;
    else
        cout<<"N"<<endl;
    }
    return 0;
}
