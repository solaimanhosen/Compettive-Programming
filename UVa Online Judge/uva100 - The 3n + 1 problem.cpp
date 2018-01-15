#include <iostream>

using namespace std;

int FindCycleLength(long long num)
{
    int count=1;
    while(num!=1)
    {
        if(num%2==1)
        {
             num=3*num+1;
             count++;
        }

        else{
            num/=2;
            count++;
        }
    }

    return count;
}



int main()
{
    long long num1,num2, CycleLength=0, MaxCycleLength=0,i;

    while(cin>>num1>>num2){
    if(num1<=num2)
    {
        MaxCycleLength=0;
        for( i=num1 ; i<=num2 ; i++)
        {
            CycleLength=FindCycleLength(i);

            if(CycleLength>MaxCycleLength)
                MaxCycleLength=CycleLength;
        }
    }
    else
    {
        MaxCycleLength=0;
        for(i=num2 ; i<=num1 ; i++)
        {
             CycleLength=FindCycleLength(i);

            if(CycleLength>MaxCycleLength)
                MaxCycleLength=CycleLength;
        }
    }
    cout<<num1<<" "<<num2<<" "<<MaxCycleLength<<endl;
    }

    return 0;
}
