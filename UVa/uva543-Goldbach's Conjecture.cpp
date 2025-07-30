#include <bits/stdc++.h>

using namespace std;

int prime[1000000], sign[1000000];

void primeGen()
{
    int i ,j, k=0;
    for(i = 2; i<=1000; i++){
        if(sign[i]==0){
            for(j = i + i; j<= 1000000; j+= i)
                sign[j] = 1;
        }
    }
    for(i = 2; i<= 1000000; i++){
        if(sign[i]==0)
            prime[k++] = i;
    }
}

int main()
{
    primeGen();
    int num, num1, i;
    while(cin>>num && num!= 0){
        for( i =0; prime[i]<=num/2; i++ ){
            num1 = num - prime[i];
            if(sign[num1] == 0){
                cout<<num<<" = "<<prime[i]<<" + "<<num1<<endl;
                break;
            }
        }
        if(i>num/2)
            cout<<"Goldbach's conjecture is wrong."<<endl;
    }
    return 0;
}
