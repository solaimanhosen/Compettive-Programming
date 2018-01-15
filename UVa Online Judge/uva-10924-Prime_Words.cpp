#include <bits/stdc++.h>

using namespace std;

int main()
{
    string word;
    int i, num;
    while(cin>>word){
        num = 0;
        for ( i = 0; word[i]!=NULL; i++){
            if(word[i]>='a' && word[i]<='z')num+=(word[i]-96);
            else num+=(word[i]-38);
        }
        for(i = 2; i<=sqrt(num); i++){
            if(num%i==0)
                break;
        }
        if(i>sqrt(num))
            cout<<"It is a prime word"<<endl;
        else
            cout<<"It is not a prime word"<<endl;
    }

    return 0;
}
