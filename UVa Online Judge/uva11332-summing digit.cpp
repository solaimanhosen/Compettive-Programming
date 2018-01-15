#include <iostream>

using namespace std;

int SumDigit(int num)
{
    int sum=0;
    while(num>10)
        {
            sum+=num%10;
            num/=10;
        }
    sum+=num;
    if(sum<10)
        return sum;
    else
        return SumDigit(sum);

}


int main()
{
    int num;

    while(cin>>num && num!=0)
    {
        cout<<SumDigit(num)<<endl;
    }
    return 0;
}
