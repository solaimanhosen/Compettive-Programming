#include <iostream>

using namespace std;

int sum(int n)
{
    lebel:
    int sum=0;
    while(true)
    {
        sum+=(n%10);
        if(n<10)
        {
            sum+=n;
            break;
        }
    }

    if(sum>=10)
    {
        n=sum;
        goto lebel;
    }
    else
        return n;
}

int main()
{
    int n;
    while((cin>>n)!=0)
    {
        cout<<sum(n)<<endl;
    }



    return 0;
}
