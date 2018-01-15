#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testCase , observe, party , interval[100], i , j, hartal[4000], counter;
    cin>>testCase;
    while(testCase--){
        cin>>observe;

        for(i = 1; i <= observe; i++)
            hartal[i] = 0;
        cin>>party;
        for(i = 0; i< party; i++)
            cin>> interval[i];
        for(i = 0; i<party;i++)
            for(j = interval[i]; j<=observe; j+= interval[i])
                hartal[j] = 1;
        for(i = 6; i <= observe; i+=7)
            hartal[i] = 0;
        for(i = 7; i <= observe; i+=7)
            hartal[i] = 0;
        counter = 0;
        for(i = 1; i<=observe; i++)
            if(hartal[i] == 1)
                counter++;
        cout<<counter<<endl;
    }
    return 0;
}
