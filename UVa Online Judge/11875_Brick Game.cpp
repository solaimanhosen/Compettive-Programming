#include<bits/stdc++.h>
using namespace std;
int main()
{
    int testCase;
    int n;
    int ary[11];
    cin>>testCase;
    for(int i=1; i<=testCase ; i++)
    {
        cin>>n;
        for(int j=0; j<n; j++)
        {
            cin>>ary[j];
        }
        sort(ary+0,ary+n);
        int y;
        y=n/2;
        cout<< "Case "<< i << ": "<< ary[y]<< endl ;
    }

}
