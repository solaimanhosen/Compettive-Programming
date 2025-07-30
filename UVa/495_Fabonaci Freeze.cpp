#include<bits/stdc++.h>
using namespace std;
#define maxnum 5001
#define maxdigit 1050

int fibo[maxnum][maxdigit];
void precal()
{
    fibo[0][0]=0;
    fibo[1][0]=1;
    int carry;
    for(int i=2; i<maxnum; i++)
    {
        carry=0;
        for(int j=0; j<maxdigit; j++)
        {
            int num=fibo[i-1][j]+fibo[i-2][j]+carry;
            fibo[i][j]=num%10;
            carry=num/10;
        }
    }

}

int main()
{
    precal();
    int input;
    while(scanf("%d",&input)==1)
    {
        if(input==0){
            cout<<"The Fibonacci number for "<<input<< " is "<< input<<endl;
        }
        else
        {
            cout<<"The Fibonacci number for "<<input<< " is " ;
        int m=maxdigit-1;
        while(fibo[input][m]==0 && m>=0)
        {
            m--;
        }
        while(m>=0)
        {
            cout<<fibo[input][m];
            m--;
        }
        cout<<endl;

        }


    }
    return 0;
}
