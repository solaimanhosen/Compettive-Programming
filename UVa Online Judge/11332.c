#include <stdio.h>

int sum1(int n)
{
    int sum=0;
    while(1)
    {
        sum+=(n%10);
        n/=10;
        if(n<10)
        {
            sum+=n;
            break;
        }
    }
    return sum;
}

int sum(int n)
{
    int sum=0;
    while(1)
    {
        sum=sum1(n);
        n=sum;
        if(n<10)
        {
            break;
        }
    }
    return n;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=0)
    {
        if(n==0)
            break;
        else if(n>=10)
             printf("%d\n",sum(n));
        else
            printf("%d\n",n);
    }

    return 0;
}
