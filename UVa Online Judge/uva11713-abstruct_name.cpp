#include <bits/stdc++.h>

using namespace std;

bool isPositive(string name1, string name2)
{
    int i;
    for(i = 0; i< name1.length(); i++){
        if(name1[i] == 'a' || name1[i] == 'e' || name1[i] == 'i' || name1[i] == 'o' || name1[i] == 'u'){
            if(name2[i] != 'a' && name2[i] != 'e' && name2[i] != 'i' && name2[i] != 'o' && name2[i] != 'u')
                return false;
        }
        else{
            if(name1[i] != name2[i]) return false;
        }
    }
    return true;
}

int main()
{
    int t, i, j;
    string str1, str2;
    cin>>t;
    while(t--){
        cin>>str1>>str2;
        if(str1.length() != str2.length()) cout<<"No"<<endl;
        else{
            if(isPositive(str1, str2)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
