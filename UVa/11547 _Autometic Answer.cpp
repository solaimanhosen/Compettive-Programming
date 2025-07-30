#include<bits/stdc++.h>
using namespace std;
int main()
{
    int testCase;
    cin>>testCase;
    while(testCase>0)
    {
        long long int input;
        scanf("%lld",&input);
        long long  int y=((((((input*567)/9)+7492)*235)/47)-498);
        if(y<0){
            y=y*(-1);
        }
        int x=0;
        int c=0;
        while(y>0)
        {
            x=y%10;
            c++;
            if(c==2)
            {
                break;
            }
            y=y/10;


        }
        cout<< x <<endl;

        testCase--;

    }
    return 0;
}
