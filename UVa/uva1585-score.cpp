#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, score, temp;
    string word;
    cin>>t;
    while(t--){
        score = 0;
        temp = 1;
        cin>>word;
        for(int i = 0; word[i]!='\0'; i++){
            if(word[i]=='O'){score+=temp;temp++;}
            else {temp=1;}
        }
        cout<<score<<endl;
    }
    return 0;
}
