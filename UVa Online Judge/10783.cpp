#include <iostream>

using namespace std;

int main()
{
    int TestCase, a[105], b[105], initial;
    cin>>TestCase;int sum[TestCase], i;
    for(initial=0;initial<TestCase;initial++){
        sum[initial]=0;
        cin>>a[initial]>>b[initial];
        if(a[initial]%2==0){a[initial]+=1;}
        if(b[initial]%2==0){b[initial]-=1;}
        for(i=a[initial];i<=b[initial];i+=2){
                sum[initial]+=i;
        }
    }
    for(initial=0;initial<TestCase;initial++){
        cout<<"Case "<<initial+1<<": "<<sum[initial]<<endl;
    }
    return 0;
}
