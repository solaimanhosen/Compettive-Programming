#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long num, num1;
    int i, j, aray[50], counter , digit;
    while(cin>>num && num!= 0){
        num1 = num;
        for(i = 0; i< 50; i++)
            aray[i] = 0;
        i = 0;
        while(num!= 0){
            aray[i++] = num%2;
            num/=2;
        }
        digit = i;
        counter = 0;
        string c = "";
        for( i = digit-1; i >= 0; i--)
            c+= aray[i] + '0';

        for( i = 0; i< digit; i++)
            if(aray[i] == 1)
                counter++;
        cout<<"The parity of "<<c<<" is "<<counter<<" (mod 2)."<<endl;
    }
    return 0;
}
