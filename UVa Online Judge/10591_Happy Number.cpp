#include<bits/stdc++.h>
using namespace std;
int digitSquare(int i)
{
    int x,z=0;
    while(i>0)
    {
        x=i%10;
        z=z+(x*x);
        i=i/10;
    }
    return z;

}

int main()
{
    int ary[100000]
    int test;
    int t=0;
    cin>>test;
    while(test>0)
    {
        t++;
        int input;
        cin >>input;
        int p=input;
        p=digitSquare(p);
        cout<< p <<endl;
        if(p==1)
        {
            cout<< "Case #"<<t<<": "<< input <<"is a Happy number."<<endl;
            break;
        }

        if(p==input)
        {
            cout<< "Case #"<<t<<": "<< input <<"is an Unhappy number."<<endl;
            break;
        }


        test--;
    }
    return 0;
}

