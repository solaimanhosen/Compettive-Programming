#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,r,i = 1,counter;
    while(cin>>r>>n && (n != 0 && r != 0)){
        counter = 0;
        r -= n;
        while(r>0){
            r -= n;
            counter++;
        }
        if(counter <= 26)
            cout<<"Case "<<i++<<": "<<counter<<endl;
        else
            cout<<"Case "<<i++<<": impossible"<<endl;

    }
    return 0;
}
