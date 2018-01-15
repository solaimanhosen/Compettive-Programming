#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, num[3], i, j,temp;
    cin>>t;
    while(t--){
        cin>>num[0]>>num[1]>>num[2];
        for(i = 1; i <= 2; i++)
            for(j = 0; j <= 1; j++)
                if(num[j]>num[j+1]){
                    temp = num[j];
                    num[j] = num[j+1];
                    num[j+1] = temp;
                }
        if(num[0] + num[1] > num[2])
            cout<<"OK"<<endl;
        else
            cout<<"Wrong!!"<<endl;
    }
    return 0;
}
